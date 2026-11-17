
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =====================================
// UVA V0.2 - Ojos con personalidad
// Hardware: ESP32 + OLED SSD1306
// =====================================

#define ANCHO 128
#define ALTO 64
#define OLED_ADDR 0x3C

#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, -1);

// Estados emocionales de UVA
enum Expresion {
    NORMAL,
    FELIZ,
    SORPRESA,
    DORMIDO,
    PENSANDO
};

Expresion expresionActual = NORMAL;

int miradaActual = 0;
int miradaObjetivo = 0;

unsigned long ultimoFrame = 0;

// =====================================
// OJOS NORMALES
// =====================================

void dibujarOjosNormales(int altoOjos) {
    altoOjos = constrain(altoOjos, 2, 30);

    int y = 32 - altoOjos / 2;
    int radio = min(8, altoOjos / 2);

    oled.fillRoundRect(
        27 + miradaActual, y,
        24, altoOjos, radio,
        SSD1306_WHITE
    );

    oled.fillRoundRect(
        77 + miradaActual, y,
        24, altoOjos, radio,
        SSD1306_WHITE
    );
}

// =====================================
// OJOS FELICES
// =====================================

void dibujarOjoFeliz(int centroX) {
    for (int dx = -14; dx <= 14; dx += 2) {
        int y = 28 + (dx * dx) / 28;

        oled.fillCircle(
            centroX + dx, y,
            2, SSD1306_WHITE
        );
    }
}

void dibujarFeliz() {
    dibujarOjoFeliz(39);
    dibujarOjoFeliz(89);
}

// =====================================
// OJOS SORPRENDIDOS
// =====================================

void dibujarSorpresa() {
    oled.fillCircle(39, 32, 15, SSD1306_WHITE);
    oled.fillCircle(89, 32, 15, SSD1306_WHITE);

    oled.fillCircle(39, 32, 5, SSD1306_BLACK);
    oled.fillCircle(89, 32, 5, SSD1306_BLACK);
}

// =====================================
// OJOS DORMIDOS
// =====================================

void dibujarDormido(unsigned long tiempo) {
    oled.fillRoundRect(27, 31, 24, 4, 2, SSD1306_WHITE);
    oled.fillRoundRect(77, 31, 24, 4, 2, SSD1306_WHITE);

    // Una pequeña Z que aparece y desaparece
    if ((tiempo / 900) % 2 == 0) {
        oled.setTextSize(1);
        oled.setTextColor(SSD1306_WHITE);
        oled.setCursor(109, 10);
        oled.print("Z");
    }
}

// =====================================
// OJOS PENSANDO
// =====================================

void dibujarPensando(unsigned long tiempo) {
    oled.fillRoundRect(27, 17, 24, 30, 8, SSD1306_WHITE);
    oled.fillRoundRect(77, 23, 24, 19, 7, SSD1306_WHITE);

    int puntos = (tiempo / 450) % 4;

    for (int i = 0; i < puntos; i++) {
        oled.fillCircle(
            106 + (i * 7),
            9,
            2,
            SSD1306_WHITE
        );
    }
}

// =====================================
// PARPADEO PROGRESIVO
// =====================================

int calcularAltoParpadeo(unsigned long tiempo) {
    unsigned long fase = tiempo % 3600UL;

    if (fase < 80) {
        return 30 - (fase * 28) / 80;
    }

    if (fase < 160) {
        return 2 + ((fase - 80) * 28) / 80;
    }

    return 30;
}

// =====================================
// SECUENCIA DE EMOCIONES
// =====================================

void actualizarEmocion(unsigned long tiempo) {
    unsigned long ciclo = tiempo % 20000UL;

    miradaObjetivo = 0;

    if (ciclo < 2500) {
        expresionActual = NORMAL;
    }
    else if (ciclo < 4500) {
        expresionActual = NORMAL;
        miradaObjetivo = -10;
    }
    else if (ciclo < 6500) {
        expresionActual = NORMAL;
        miradaObjetivo = 10;
    }
    else if (ciclo < 9000) {
        expresionActual = FELIZ;
    }
    else if (ciclo < 11500) {
        expresionActual = SORPRESA;
    }
    else if (ciclo < 14500) {
        expresionActual = DORMIDO;
    }
    else if (ciclo < 16800) {
        expresionActual = PENSANDO;
    }
    else {
        expresionActual = NORMAL;
    }

    // Movimiento suave hacia el objetivo
    if (miradaActual < miradaObjetivo) {
        miradaActual = min(miradaActual + 2, miradaObjetivo);
    }
    else if (miradaActual > miradaObjetivo) {
        miradaActual = max(miradaActual - 2, miradaObjetivo);
    }
}

// =====================================
// ACTUALIZAR PANTALLA
// =====================================

void actualizarPantalla(unsigned long tiempo) {
    oled.clearDisplay();

    switch (expresionActual) {
        case NORMAL:
            dibujarOjosNormales(
                calcularAltoParpadeo(tiempo)
            );
            break;

        case FELIZ:
            dibujarFeliz();
            break;

        case SORPRESA:
            dibujarSorpresa();
            break;

        case DORMIDO:
            dibujarDormido(tiempo);
            break;

        case PENSANDO:
            dibujarPensando(tiempo);
            break;
    }

    oled.display();
}

// =====================================
// SETUP
// =====================================

void setup() {
    Serial.begin(115200);

    Wire.begin(SDA_PIN, SCL_PIN);

    if (!oled.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDR,
        true,
        false
    )) {
        Serial.println("Error: OLED no detectado");

        while (true) {
            delay(1000);
        }
    }

    oled.clearDisplay();
    oled.display();

    Serial.println("UVA V0.2 iniciado");
}

// =====================================
// LOOP
// =====================================

void loop() {
    unsigned long ahora = millis();

    // Aproximadamente 25 FPS
    if (ahora - ultimoFrame < 40) {
        return;
    }

    ultimoFrame = ahora;

    actualizarEmocion(ahora);
    actualizarPantalla(ahora);
}

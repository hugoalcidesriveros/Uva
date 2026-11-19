
<div align="center">

# 🍇 UVA

### Robot inteligente inspirado en Mendoza

**Robótica · Sistemas embebidos · Inteligencia artificial · Diseño 3D**

Un pequeño robot de escritorio que combina electrónica,
software e inteligencia artificial con la identidad
vitivinícola de Mendoza, Argentina.


<p align="center">
  <img
    src="Robot%20uva%20de%20escritorio%20adorable.png"
    alt="UVA - Robot inteligente de escritorio"
    width="300"
  />
</p>


![Estado](https://img.shields.io/badge/Estado-En_desarrollo-F59E0B?style=for-the-badge)
![ESP32](https://img.shields.io/badge/ESP32-Embedded-323232?style=for-the-badge&logo=espressif&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![PlatformIO](https://img.shields.io/badge/PlatformIO-FF7F00?style=for-the-badge&logo=platformio&logoColor=white)

**Desarrollado por [Hugo Alcides Riveros](https://github.com/hugoalcidesriveros)**

📍 Mendoza, Argentina

</div>

---

## 📖 Descripción del proyecto

**UVA** es un proyecto experimental de robótica e inteligencia artificial que busca desarrollar un robot compacto, expresivo e interactivo.

Su diseño está inspirado en una uva, símbolo representativo de Mendoza y su cultura vitivinícola.

El proyecto integra diferentes disciplinas:

- Electrónica y sistemas embebidos.
- Desarrollo de software.
- Inteligencia artificial e interacción por voz.
- Diseño mecánico y modelado 3D.
- Integración de hardware y software.

El objetivo es construir un robot físico capaz de interactuar con personas de forma natural, expresar emociones mediante una pantalla y evolucionar hacia distintas aplicaciones.

---

## 🎯 Objetivos

### Objetivo principal

Diseñar y construir un robot inteligente de escritorio, integrando hardware, software e inteligencia artificial en una plataforma física original.

### Objetivos específicos

- Desarrollar un sistema embebido basado en ESP32.
- Implementar expresiones faciales animadas mediante OLED.
- Integrar comunicación entre el microcontrolador y un backend.
- Experimentar con modelos de inteligencia artificial.
- Desarrollar una interfaz de interacción por voz.
- Diseñar una carcasa mediante herramientas CAD.
- Construir y evaluar prototipos físicos.
- Explorar futuras aplicaciones educativas y turísticas.

---

## 🧠 Arquitectura del sistema

UVA se plantea como una arquitectura modular, separando el control del hardware de los servicios de procesamiento e inteligencia artificial.

```text
              ┌─────────────────────┐
              │       USUARIO       │
              └──────────┬──────────┘
                         │
                  Interacción
                         │
              ┌──────────▼──────────┐
              │         UVA         │
              │   Robot físico      │
              └──────────┬──────────┘
                         │
              ┌──────────▼──────────┐
              │        ESP32        │
              │ Control embebido    │
              └─────┬─────────┬─────┘
                    │         │
             ┌──────▼───┐ ┌───▼─────────┐
             │ Pantalla │ │ Periféricos │
             │   OLED   │ │ de audio    │
             └──────────┘ └─────────────┘
                    │
          Comunicación con backend
                    │
              ┌─────▼───────────────┐
              │       BACKEND       │
              │ Lógica e integración│
              └─────────┬───────────┘
                        │
              ┌─────────▼───────────┐
              │ Servicios de IA     │
              │ y procesamiento     │
              └─────────────────────┘
```

> Esta arquitectura representa el diseño previsto del sistema. La integración completa se encuentra en desarrollo.

---

## 🔧 Tecnologías utilizadas

### Hardware y sistemas embebidos

| Tecnología | Aplicación |
|---|---|
| ESP32 | Control principal del robot |
| OLED | Expresiones faciales animadas |
| C/C++ | Programación del firmware |
| PlatformIO | Desarrollo y compilación |
| Electrónica digital | Integración de periféricos |

### Software e inteligencia artificial

| Tecnología | Aplicación |
|---|---|
| TypeScript | Desarrollo de componentes de software |
| HTML | Interfaces de prueba |
| Gemini AI | Integración experimental de IA |
| Backend | Comunicación y procesamiento |
| Git / GitHub | Control de versiones |

### Diseño mecánico

| Herramienta | Aplicación |
|---|---|
| FreeCAD | Modelado 3D de la carcasa |
| CAD paramétrico | Diseño de componentes |
| Impresión 3D | Fabricación prevista del prototipo |

---

## 🤖 Identidad y diseño físico

UVA tiene una identidad visual inspirada en una uva.

El diseño busca combinar una apariencia amigable con una estructura que pueda fabricarse y ensamblarse físicamente.

### Características de diseño

- Cuerpo compacto y redondeado.
- Carcasa inspirada en una uva.
- Color principal bordó/violeta.
- Pantalla frontal para expresiones.
- Ojos digitales de color cian.
- Elementos decorativos inspirados en la vid.
- Diseño orientado a fabricación mediante impresión 3D.

### Diseño conceptual


<p align="center">
  <img
    src="Robot%20uva%20de%20escritorio%20adorable.png"
    alt="UVA - Robot inteligente de escritorio"
    width="300"
  />
</p>


*Representación visual del diseño objetivo. No corresponde a una fotografía de un prototipo terminado.*

### Modelado en FreeCAD

La carcasa está siendo desarrollada mediante modelado CAD, considerando el espacio necesario para los componentes electrónicos y su posterior ensamblaje.

El proceso incluye:

1. Diseño de la geometría exterior.
2. Modelado de los alojamientos internos.
3. Adaptación de la pantalla y periféricos.
4. Evaluación de espesores y uniones.
5. Preparación para futuras pruebas de impresión 3D.

---

## 👀 Sistema de expresiones

Una de las características centrales de UVA es su capacidad proyectada para comunicar estados mediante expresiones digitales.

El firmware incluye trabajo sobre animaciones para una pantalla OLED.

### Expresiones previstas

- Estado neutral.
- Alegría.
- Curiosidad.
- Parpadeo.
- Escucha.
- Procesamiento de respuestas.

El objetivo es conseguir expresiones fluidas, reconocibles y coherentes con la personalidad del robot.

---

## 🎙️ Voz e inteligencia artificial

UVA busca incorporar interacción conversacional mediante una arquitectura que combine el dispositivo físico con servicios de procesamiento.

El desarrollo contempla:

- Captura de voz mediante hardware de audio.
- Procesamiento de solicitudes.
- Integración con servicios de inteligencia artificial.
- Generación de respuestas.
- Reproducción de voz.
- Coordinación de respuestas y expresiones faciales.

El repositorio incluye trabajo inicial de backend e integración experimental con Gemini AI.

**La conversación por voz completamente integrada en el robot físico es una funcionalidad en desarrollo.**

---

## 🗂️ Estructura del repositorio

```text
Uva/
│
├── backend/
│   └── Servicios e integración de IA
│
├── include/
│   └── Archivos de cabecera
│
├── lib/
│   └── Bibliotecas del proyecto
│
├── src/
│   └── Código fuente del firmware
│
├── test/
│   └── Pruebas
│
├── platformio.ini
│
├── .gitignore
│
└── README.md
```

El proyecto utiliza PlatformIO para organizar el desarrollo del firmware.

---

## 🚧 Estado del desarrollo

| Componente | Estado |
|---|---|
| Concepto e identidad visual | Definidos |
| Diseño de carcasa en FreeCAD | En desarrollo |
| Firmware ESP32 | En desarrollo |
| Expresiones OLED | Implementación inicial |
| Backend | Implementación inicial |
| Integración Gemini AI | Experimental |
| Interacción por voz física | Pendiente de integración |
| Ensamblaje del robot | Pendiente |
| Pruebas del sistema completo | Pendiente |

Los estados se actualizarán a medida que se validen las funcionalidades.

---

## 🗺️ Hoja de ruta

### Fase 1 — Concepto y diseño

- [x] Definir la identidad del robot.
- [x] Diseñar la apariencia conceptual.
- [x] Crear el repositorio.
- [x] Establecer el entorno PlatformIO.
- [ ] Finalizar el diseño mecánico.

### Fase 2 — Sistema embebido

- [ ] Validar el firmware de expresiones OLED.
- [ ] Integrar los periféricos necesarios.
- [ ] Desarrollar una máquina de estados.
- [ ] Realizar pruebas de funcionamiento.

### Fase 3 — Inteligencia artificial

- [ ] Validar la comunicación con el backend.
- [ ] Probar la integración con servicios de IA.
- [ ] Integrar entrada de voz.
- [ ] Integrar salida de audio.
- [ ] Coordinar voz y expresiones.

### Fase 4 — Prototipo físico

- [ ] Preparar las piezas para impresión 3D.
- [ ] Fabricar la carcasa.
- [ ] Ensamblar los componentes.
- [ ] Realizar pruebas de integración.
- [ ] Documentar el prototipo funcional.

### Fase 5 — Evolución

- [ ] Mejorar la interacción conversacional.
- [ ] Optimizar la arquitectura del sistema.
- [ ] Explorar aplicaciones educativas.
- [ ] Evaluar aplicaciones como guía turística.

---

## 🍷 Aplicaciones futuras

UVA está concebido inicialmente como robot de escritorio experimental.

A largo plazo se contempla explorar su uso en:

**Asistente de escritorio**

Interacción con usuarios, respuestas conversacionales y expresiones digitales.

**Educación tecnológica**

Demostración de conceptos de programación, electrónica, robótica e inteligencia artificial.

**Turismo en Mendoza**

Posible asistente interactivo para bodegas, espacios turísticos y actividades culturales.

Estas aplicaciones representan líneas de desarrollo futuras.

---

## 📚 Documentación

El proyecto se encuentra en evolución.

Se prevé incorporar progresivamente:

- Diagramas electrónicos.
- Esquemas de conexión.
- Documentación del firmware.
- Arquitectura del backend.
- Imágenes del proceso CAD.
- Pruebas de hardware.
- Fotografías y videos del prototipo.

---

## 👨‍💻 Autor

**Hugo Alcides Riveros**

Software Developer | IoT & Embedded Systems

Mendoza, Argentina

[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/hugoalcidesriveros)

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alcitec)

---

<div align="center">

### 🍇 UVA — Tecnología con identidad mendocina

*Del concepto al prototipo: explorando la integración entre robótica, software e inteligencia artificial.*

</div>

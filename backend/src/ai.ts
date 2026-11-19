
import { loadEnvFile } from "node:process";
import { GoogleGenAI } from "@google/genai";

// Cargar la clave privada
loadEnvFile(".env");

const apiKey = process.env.GEMINI_API_KEY;

if (!apiKey) {
  throw new Error("Falta GEMINI_API_KEY en .env");
}

const ai = new GoogleGenAI({ apiKey });

// Función reutilizable para conversar con UVA
export async function responderUVA(
  pregunta: string
): Promise<string> {

  const respuesta = await ai.models.generateContent({
    model: "gemini-3.5-flash-lite",
    contents: pregunta,
    config: {
      systemInstruction: `
        Sos UVA, un pequeño robot inteligente
        creado en Mendoza, Argentina.

        Tu personalidad es:
        - Simpática y amigable.
        - Curiosa.
        - Con identidad mendocina.
        - Natural al conversar.

        Respondé siempre en español argentino,
        salvo que el usuario solicite otro idioma.

        Tus respuestas deben ser claras,
        relativamente breves y conversacionales.

        No inventes información que no conocés.
      `
    }
  });

  return respuesta.text ?? "No pude generar una respuesta.";
}

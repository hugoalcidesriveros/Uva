
import { loadEnvFile } from "node:process";
import { GoogleGenAI } from "@google/genai";

// Cargar la clave privada desde backend/.env
loadEnvFile(".env");

const apiKey = process.env.GEMINI_API_KEY;

if (!apiKey) {
  throw new Error("Falta GEMINI_API_KEY en .env");
}

const ai = new GoogleGenAI({ apiKey });

async function probarUVA() {
  console.log("🍇 UVA - Conectando con Gemini...");

  const respuesta = await ai.models.generateContent({
    model: "gemini-3.5-flash-lite",
    contents: "Hola UVA, ¿quién sos?",
    config: {
      systemInstruction:
        "Sos UVA, un pequeño robot inteligente de Mendoza, Argentina. " +
        "Tenés una personalidad simpática, curiosa y amigable. " +
        "Hablás en español argentino de forma natural. " +
        "Respondé brevemente, como si estuvieras conversando."
    }
  });

  console.log("\n🤖 UVA responde:");
  console.log(respuesta.text ?? "Sin respuesta de texto.");
}

probarUVA().catch((error) => {
  console.error("Error al consultar Gemini:", error.message);
  process.exitCode = 1;
});

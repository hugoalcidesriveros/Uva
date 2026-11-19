
import { createServer } from "node:http";
import { responderUVA } from "./ai";
import { readFile } from "node:fs/promises";
import { join } from "node:path";

const PORT = 3000;
const HOST = "127.0.0.1";

const server = createServer(async (req, res) => {

    res.setHeader(
        "Content-Type",
        "application/json; charset=utf-8"
    );

    // Estado principal

    if (req.method === "GET" && req.url === "/") {
        try {
            const ruta = join(process.cwd(), "public", "index.html");
            const html = await readFile(ruta, "utf8");

            res.writeHead(200, {
                "Content-Type": "text/html; charset=utf-8"
            });

            res.end(html);

        } catch (error) {
            console.error("Error al cargar la interfaz:", error);

            res.writeHead(500);
            res.end(JSON.stringify({
                error: "No se pudo cargar la interfaz de UVA"
            }));
        }

        return;
    }


    // Comprobación de funcionamiento
    if (req.method === "GET" && req.url === "/health") {
        res.writeHead(200);
        res.end(JSON.stringify({ status: "ok" }));
        return;
    }

    // Nueva ruta de inteligencia artificial
    if (req.method === "POST" && req.url === "/preguntar") {
        try {
            let cuerpo = "";

            for await (const fragmento of req) {
                cuerpo += fragmento.toString();

                if (Buffer.byteLength(cuerpo, "utf8") > 4096) {
                    res.writeHead(413);
                    res.end(JSON.stringify({
                        error: "Solicitud demasiado grande"
                    }));
                    return;
                }
            }

            const datos = JSON.parse(cuerpo);
            const pregunta = datos?.pregunta;

            if (
                typeof pregunta !== "string" ||
                !pregunta.trim() ||
                pregunta.length > 500
            ) {
                res.writeHead(400);
                res.end(JSON.stringify({
                    error: "La pregunta debe tener entre 1 y 500 caracteres"
                }));
                return;
            }

            console.log("🍇 UVA recibió una pregunta");

            const respuesta = await responderUVA(pregunta.trim());

            res.writeHead(200);
            res.end(JSON.stringify({
                proyecto: "UVA",
                pregunta: pregunta.trim(),
                respuesta
            }));

        } catch (error) {
            if (error instanceof SyntaxError) {
                res.writeHead(400);
                res.end(JSON.stringify({
                    error: "JSON inválido"
                }));
                return;
            }

            console.error("Error de IA:", error);

            res.writeHead(502);
            res.end(JSON.stringify({
                error: "No se pudo obtener la respuesta de Gemini"
            }));
        }

        return;
    }

    res.writeHead(404);
    res.end(JSON.stringify({
        error: "Ruta no encontrada"
    }));
});

server.listen(PORT, HOST, () => {
    console.log("🍇 UVA - Servidor con IA iniciado");
    console.log(`http://localhost:${PORT}`);
});

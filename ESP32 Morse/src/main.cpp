#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = "";

const int ledPin = 2;
WebServer server(80);
String receivedMessage = "";

// Duração base em ms
const int dotDuration = 200;
const int dashDuration = dotDuration * 3;
const int symbolSpace = dotDuration;
const int letterSpace = dotDuration * 3;
const int wordSpace = dotDuration * 7;

String morseCode(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    case ' ': return " ";
    default: return "";
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(symbolSpace);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(symbolSpace);
}

void sendMorse(String message) {
  for (int i = 0; i < message.length(); i++) {
    if (message[i] == ' ') {
      delay(wordSpace);
      continue;
    }

    String code = morseCode(message[i]);
    for (int j = 0; j < code.length(); j++) {
      if (code[j] == '.') dot();
      else if (code[j] == '-') dash();
    }
    delay(letterSpace);
  }
}

// Página HTML simples
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head><title>ESP32 Morse</title></head>
  <body style="display: flex; justify-content: center; align-items: center;">
    <h2>Enviar mensagem em Codigo Morse</h2>
    <form action="/send" method="POST">
      <input type="text" name="message" placeholder="Digite sua mensagem" required>
      <input type="submit" value="Enviar">
    </form>
  </body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void handleSend() {
  if (server.hasArg("message")) {
    receivedMessage = server.arg("message");
    server.send(200, "text/html", "<h3>Mensagem recebida: " + receivedMessage + "</h3><a href='/'>Voltar</a>");
    sendMorse(receivedMessage);
  } else {
    server.send(400, "text/plain", "Mensagem não recebida.");
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("Iniciando setup");

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado com IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/send", HTTP_POST, handleSend);
  server.begin();
  Serial.println("Servidor HTTP iniciado.");
}


void loop() {
  server.handleClient();
}


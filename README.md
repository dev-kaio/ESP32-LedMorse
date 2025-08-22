ESP32-LedMorse

Um transmissor de código Morse com LED, desenvolvido para o microcontrolador ESP32. Ideal para aprender e praticar código Morse de forma prática e divertida.

📌 Objetivo

Este projeto converte texto em código Morse e transmite a mensagem por meio de um LED conectado ao ESP32. É uma excelente ferramenta para iniciantes que desejam entender o funcionamento do código Morse e a programação de microcontroladores.

⚙️ Funcionalidades

Conversão de Texto para Código Morse: Insira qualquer texto e o sistema o converterá automaticamente para código Morse.

Transmissão Visual: O LED pisca de acordo com o código Morse gerado.

Configuração Simples: Fácil de configurar e utilizar, com código aberto e bem documentado.

🛠️ Requisitos

Hardware:

Placa de desenvolvimento ESP32

LED (qualquer tipo compatível)

Resistor de 220Ω

Jumpers para conexões

Software:

Arduino IDE com suporte para ESP32

Biblioteca MorseEncoder (opcional, para funcionalidades avançadas)

📦 Instalação

Clone o repositório:

git clone https://github.com/dev-kaio/ESP32-LedMorse.git
cd ESP32-LedMorse


Abra o código no Arduino IDE:

Vá em Arquivo > Abrir e selecione o arquivo ESP32_LedMorse.ino.

Selecione a placa e a porta:

Vá em Ferramentas > Placa e escolha a opção correspondente ao seu modelo de ESP32.

Vá em Ferramentas > Porta e selecione a porta à qual o ESP32 está conectado.

Carregue o código:

Clique no botão Carregar (ícone de seta para a direita) para compilar e enviar o código para o ESP32.

🔌 Conexões

LED:

Anodo (positivo): Conecte ao pino GPIO 23 do ESP32.

Catodo (negativo): Conecte ao GND do ESP32, passando por um resistor de 220Ω.

📝 Personalização

Mensagem: No código, altere a variável mensagem para o texto que deseja transmitir.

Velocidade: Ajuste o tempo de pausa entre os sinais de ponto e traço para controlar a velocidade da transmissão.

📸 Exemplo de Montagem

📚 Referências

MorseEncoder - Biblioteca para Arduino

ESP32 Blink LED Morse Code - Repositório de Exemplo

📬 Contato

Para dúvidas, sugestões ou contribuições, entre em contato:

Email: seuemail@example.com

GitHub: https://github.com/dev-kaio

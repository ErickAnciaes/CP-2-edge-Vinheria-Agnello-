## 🍷🍇 Checkpoint 2: Monitoramento Ambiental – Vinheria Agnello
Bem-vindo ao repositório do projeto Vinheria Agnello – Checkpoint 2, um sistema de monitoramento inteligente desenvolvido com Arduino para auxiliar na conservação ideal dos vinhos em estoque. Após o sucesso da primeira fase do projeto com a criação do e-commerce, os proprietários solicitaram a implementação de um controle preciso de temperatura, umidade e luminosidade no ambiente de armazenamento. 🛠️🌡️💡

## 🎯 Objetivo do Projeto
Criar um sistema funcional que monitore os principais fatores ambientais que influenciam na qualidade do vinho: temperatura, umidade e luminosidade, apresentando alertas visuais e sonoros, além de exibir as informações em um display LCD.

## 🧭 Estrutura do Projeto
Este projeto utiliza sensores e atuadores conectados a um Arduino, com as seguintes funcionalidades:

🔹 Sensor DHT11: Mede temperatura e umidade.
🔹 Sensor de luminosidade (LDR): Detecta os níveis de luz ambiente.
🔹 Display LCD: Exibe informações de leitura e mensagens de status.
🔹 LEDs: Indicadores visuais de alerta (verde, amarelo e vermelho).
🔹 Buzzer: Alerta sonoro em condições críticas.

## 🚦 Regras de Funcionamento
🌞 Luminosidade
🌑 Ambiente Escuro: LED verde aceso.

🌗 Meia-luz: LED amarelo aceso + LCD com mensagem "Ambiente a meia luz".

☀️ Muito Claro: LED vermelho aceso + LCD com "Ambiente muito claro" + Buzzer ativo.

🌡️ Temperatura
✅ Entre 10°C e 15°C: LCD mostra "Temperatura OK" + valor atual.

⚠️ Abaixo de 10°C: LCD mostra "Temp. Baixa" + LED amarelo + Buzzer ativo.

⚠️ Acima de 15°C: LCD mostra "Temp. Alta" + LED amarelo + Buzzer ativo.

💧 Umidade
✅ Entre 50% e 70%: LCD mostra "Umidade OK" + valor atual.

⚠️ Abaixo de 50%: LCD mostra "Umidade Baixa" + LED vermelho + Buzzer ativo.

⚠️ Acima de 70%: LCD mostra "Umidade Alta" + LED vermelho + Buzzer ativo.

🔄 Atualização e Média de Leituras
O display exibe a média de 5 leituras feitas a cada 5 segundos, proporcionando informações mais precisas.

## 🧪 Simulação do Projeto
📍 Acesse a simulação no Tinkercad:
🔗 https://encr.pw/LinkdoTinkercad
 
 

## 🧰 Tecnologias e Recursos Utilizados
Arduino Uno

Sensor DHT11

Sensor LDR

Display LCD (I2C)

LEDs RGB

Buzzer

IDE Arduino

Tinkercad (simulação)

Lógica de controle com millis() e média de leituras

Biblioteca DHT.h

## 📽️ Apresentação em Vídeo
🎥 Link para vídeo explicativo com demonstração, desafios e soluções encontradas durante o desenvolvimento.
🔗 https://encr.pw/VideoExplicativo

## Autores

- [@erickanciaes](https://www.github.com/erickanciaes)
Nome: Erick Munhoes Anciães, RM: 561484
- [@fernandesjp](https://www.github.com/fernandesjp)
Nome: João Paulo Fernandes, RM: 563430
- [@jopedrofigueiredo](https://www.github.com/jopedrofigueiredo)
Nome: João Pedro Mendes de Figueiredo RM: 558779
- [@patricxk7](https://www.github.com/patricxk7)
Nome: Patrick Canuto dos Santos, RM: 563776

## 👨‍🏫 Professor Responsável
Lucas D. Augusto
📧 proflucas.augusto@fiap.com.br
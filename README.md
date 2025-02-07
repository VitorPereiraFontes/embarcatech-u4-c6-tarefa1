# Protocolos de comunicação

## Descrição

Este repositório contém os códigos correspondentes aos requisitos solicitados pela tarefa 1 do capítulo 4 da unidade 6 do programa de capacitação em sistemas embarcados (Embarcatech). A tarefa em questão busca incitar a utilização do protocolo de comunicação I2C para comunicar-se com um Display OLED SSD1306 e exibit informações acerda de outros componentes da placa BitDogLab, como o LED RGB.

## Requerimentos

O presente projeto deverá atender aos seguintes requerimentos:

* __Uso de interrupções:__ Todas as funcionalidades relacionadas aos botões devem ser implementadas utilizando rotinas de interrupção (IRQ). 

* __Debouncing:__ É obrigatório implementar o tratamento do bouncing dos botões via software.

* __Controle de LEDs:__ O projeto deve incluir o uso de LEDs comuns e LEDs WS2812, demonstrando o domínio de diferentes tipos de controle.

* __Utilização do Display 128 x 64:__ A utilização de fontes maiúsculas e minúsculas demonstrará o domínio do uso de bibliotecas, o entendimento do princípio de funcionamento do display, bem como, a utilização do protocolo I2C.

* __Envio de informação pela UART:__ Visa observar a compreensão sobre a comunicação serial via UART.

* __Organização do código:__ O código deve estar bem estruturado e comentado para facilitar o entendimento.

## Demonstração

Segue o link do vídeo de demonstração do projeto na placa BitDogLab.



## Instruções

Para que o projeto funcione em sua máquina, é necessário ter a extensão Raspberry Pi Pico Project instalada no VSCode.

1. Realize o clone do repositório.
2. Importe o repositório como um projeto através da extensão Raspberry Pi Pico Project.
3. Compile o projeto.
4. Caso esteja usando a placa BitDogLab ou a Raspberry Pi Pico W, faça o upload do arquivo uf2, encontrado na pasta `build` após o processo de compilação, para a placa. Caso deseje simular, abra o arquivo `diagram.json` (É necessário ter a extensão do Wokwi instalada).
Criptografia RSA
================

Método de cifração e decifração de chave pública e privada RSA.
Disciplina: Criptografia e Segurança de Redes.
Contribuidores: Rodrigo Gonçalves e Alessandro Caetano.

### Compilar projeto ###
```
$ make
```

### Executar programa ###
```
$ ./rsa <arquivo> <bits>
```

### Funções presentes no programa ###
* Função para encontrar grandes números primos, dado o número de bits como entrada
* Função para calcular MDC de dois números inteiros grandes
* Função para produzir chaves de cifração e decifração, tendo como entrada dois números primos grandes p e q utilizados no algoritmo RSA
* Função para cifração e decifração de uma mensagem

### Como usar o programa ###
* Ao executar o programa deve-se passar como parâmetros o nome do arquivo que contém a mensagem a ser cifrada e o número de bits desejado
* Coloque suas mensagens de entrada em `files/`
* As saídas geradas encontram-se em `files/`


### Observações ###
* Para compilação é necessário ter instalado na máquina a biblioteca de teoria dos números, existente em C++, chamada NTL (Number Theory Library)
* Para instalar esta biblioteca no Linux, basta digitar o comando:
```
# apt-get install libntl-dev
```


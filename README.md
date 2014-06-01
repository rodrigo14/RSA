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
./rsa
```

### Funções presentes no programa ###
* Função para encontrar grandes números primos, dado o número de bits como entrada
* Função para calcular MDC de dois números inteiros grandes
* Função para produzir chaves de cifração e decifração, tendo como entrada dois números primos grandes p e q utilizados no algoritmo RSA
* Função para cifração e decifração de uma mensagem

### Como usar o programa ###
* Para cifrar uma mensagem, deve-se editar o arquivo encontrado em `files/plaintext.txt`
* As mensagens cifradas e decifradas se encontram em `files/`


### Observações ###
* Para o programa funcionar deve-se ter instalado na máquina a biblioteca de teoria dos números, existente em C++, chamada NTL (Number Theory Library)
* Para instalar esta biblioteca no Ubuntu:
```
$ sudo apt-get install libntl-dev
```


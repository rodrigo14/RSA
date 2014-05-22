/*                           TRABALHO EMC
  Implementar o algoritmo de Miller-Selfridge-Rabin para testar se um número de 
entrada é possível primo ou composto. O algoritmo deverá ser feito em linguagem C 
e deve permitir testar mais de uma vez se o mesmo número é possível primo, ou não.

  n-1 = (2^t)m

  Aluno: Rodrigo Santana Gonçalves - 11/0139356
  Prof: Vinícius Rispoli*/
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cabecalho(){
    //Cabeçalho
    printf("\tAlgoritmo de Miller-Selfridge-Rabin\n");
    printf("\tTeste de primalidade\n\n");
}

int main(int argc, char *argv[]){
    int a, m, n, j=0, t=0;
    float x;
    
    cabecalho();
    //Entrada de dados
    printf("Escolha um n%cmero para testar\nn: ", 163);
    scanf("%d", &n);
    printf("Digite um n%cmero entre 2 e n-2\na: ", 163);
    scanf("%d", &a);
    while(a<2 || a>(n-2)){
        printf("a: ");
        scanf("%d", &a);
    }
    
    //Valor de t
    do{
        t++;
    }while(fmod((n-1)/(pow(2, t)), 2)==0);
    //Valor de m
    m = (n-1)/(pow(2, t));
    //Valor de x(0)
    x = fmod(pow(a, m), n);
    
    //Resultado
    printf("\nResultado: ");
    if(x==1 || x==n-1){
        printf("%d %c prov%cvel primo.\n", n, 130, 160);
    }else if((x!=1 || x!=n-1) && t==1){
        printf("%d %c definitivamente composto.\n", n, 130);
    }else{
        j++;
        do{
            x=fmod(pow(a, pow(2, j)*m), n);
            if(fmod(x, n)==(n-1)){
                printf("%d %c prov%cvel primo.\n", n, 130, 160);
                break;
            }else{
                j++;
            }
        }while(j!=t);
        
        if(j==t){
            x=fmod(pow(a, pow(2, t)*m), n);
            if(fmod(x, n)==n-1){
                printf("%d %c definitivamente composto.\n", n, 130);  
            }else{
                printf("%d %c prov%cvel primo.\n", n, 130, 160);
            }
        }
    }
  
  //Finalizando programa
  printf("\n______________________________________________________\n\n");
  printf("Pressione qualquer tecla para sair. . .");

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct compr {
    char n[15];
    int cod;
    float p;
    int q;
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int i, cd, qa, tam;
    struct compr c[5];

	
	 printf("Insira quantos produtos voc� deseja adicionar (at� 5)\n");
	 scanf("%d", &tam);
        fflush(stdin);
        
        if(tam > 5 || tam <= 0){
        	 printf("\nQuantidade de produtos inv�lida\n");
		
		}else{

    for (i = 0; i < tam; i++) {
        printf("\nInsira os dados do produto (%d): \n\n", i + 1);
        printf("O nome: ");
        scanf(" %14[^\n]", c[i].n);
        fflush(stdin);

        printf("O cod: ");
        scanf("%d", &c[i].cod);
        fflush(stdin);

        printf("O pre�o: ");
        scanf("%f", &c[i].p);
        fflush(stdin);

        printf("A quantidade: ");
        scanf("%d", &c[i].q);
        fflush(stdin);

    }
    
        printf("\nInsira o c�digo e a quantidade do produto desejado: ");
    scanf("%d %d", &cd, &qa);
	
	    bool encontrado = false;
    for (i = 0; i < 5; i++) {
        if (c[i].cod == cd) {
        	
            if(qa <= c[i].q){
            	printf("\nSua compra est� sendo realizada... \n");
            
			printf("\nNome: %s |", c[i].n);
            printf(" Cod: %d |", c[i].cod);
            printf(" Pre�o:  %.2f% |", c[i].p);
            printf(" Estoque atual: %d", c[i].q - qa);
            
			}else{
				printf("\nN�o h� produtos suficientes no estoque! \n");
			}
            encontrado = true;
            break;
        } 
    } 
    
    if (!encontrado) {
        printf("\nN�o h� produtos com esse c�digo\n");
   	 }
   	 return 0;
    }
}
    


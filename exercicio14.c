#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct carro {
    char marca[15];
    int ano;
    int preco;
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int p;
    struct carro c[5];
	
    strcpy(c[0].marca, "Fiat");
    c[0].ano = 2000;
    c[0].preco = 10000;
	
    strcpy(c[1].marca, "Jeep");
    c[1].ano = 2010;
    c[1].preco = 50000;
	
    strcpy(c[2].marca, "Toyota");
    c[2].ano = 2014;
    c[2].preco = 70000;
	
    strcpy(c[3].marca, "Chevrolet");
    c[3].ano = 2024;
    c[3].preco = 100000;
	
    strcpy(c[4].marca, "Subaru");
    c[4].ano = 2020;
    c[4].preco = 200000;	

    
    printf("Insira a faixa de preço desejada: ");
    scanf("%d", &p);

    

int i;
for (i = 0; i < 5; i++) {
    if (c[i].preco <= p) {
        printf("\n Marca: %s |", c[i].marca);
        printf(" Ano: %d |", c[i].ano);
        printf(" Preço: %d \n\n", c[i].preco);

	}
}

    if (p < 10000) {
        printf("\nNão há carros abaixo desse valor.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct livro {
    char ti[15];
    int ano;
    char autor[180];
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int i;
    struct livro l[5];
    char procurado[15];

    strcpy(l[0].ti, "Dom Casmurro");
    l[0].ano = 1899;
    strcpy(l[0].autor, "Machado de Assis");

    strcpy(l[1].ti, "1984");
    l[1].ano = 1949;
    strcpy(l[1].autor, "George Orwell");

    strcpy(l[2].ti, "O Alienista");
    l[2].ano = 1882;
    strcpy(l[2].autor, "Machado de Assis");

    strcpy(l[3].ti, "O Guarani");
    l[3].ano = 1857;
    strcpy(l[3].autor, "José de Alencar");

    strcpy(l[4].ti, "Sagarana");
    l[4].ano = 1946;
    strcpy(l[4].autor, "Guimarães Rosa");

    printf("Insira o título do livro desejado: ");
    scanf(" %[^\n]", procurado);

    bool encontrado = false;
    for (i = 0; i < 5; i++) {
        if (strcmp(l[i].ti, procurado) == 0) {
            printf("\nTítulo: %s |", l[i].ti);
            printf(" Ano: %d |", l[i].ano);
            printf(" Autor: %s", l[i].autor);
            encontrado = true;
            break;
        } 
    } 
    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct receita {
    char n[25];
    char in[100][180];
    int q;
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct receita c[5];
    int i, j, tam;
    char nome[25];

    printf("Insira quantas receitas você deseja adicionar (até 5): ");
    scanf("%d", &tam);
    fflush(stdin);

    if (tam > 5 || tam <= 0) {
        printf("\nQuantidade de receitas inválida\n");
        return 1;
    }

    for (i = 0; i < tam; i++) {
        printf("\nInsira os dados da receita (%d):\n", i + 1);
        printf("O nome: ");
        scanf(" %24[^\n]", c[i].n);
        fflush(stdin);

        printf("A quantidade de ingredientes: ");
        scanf("%d", &c[i].q);
        fflush(stdin);

        for (j = 0; j < c[i].q; j++) {
            printf("Ingrediente (%d): ", j + 1);
            scanf(" %179[^\n]", c[i].in[j]);
            fflush(stdin);
        }
    }

    printf("\nInsira o nome da receita desejada: ");
    scanf(" %24[^\n]", nome);

    bool encontrado = false;
    for (i = 0; i < tam; i++) {
        if (strcmp(c[i].n, nome) == 0) {
            printf("\n| Nome da Receita: %s |\n", c[i].n);
            printf("Quantidade de ingredientes: %d\n", c[i].q);
            printf("Ingredientes:\n");
            for (j = 0; j < c[i].q; j++) {
                printf("  - %s\n", c[i].in[j]);
            }
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("\nReceita não encontrada...\n");
    }

    return 0;
}


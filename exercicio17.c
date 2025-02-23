#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct eletro {
    char n[15];
    float p;
    int t;
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct eletro c[5];
    int ct = 0, i, d, hl, tam;
    float cr, por;

    printf("Insira quantos eletrodomésticos você deseja adicionar (até 5): ");
    scanf("%d", &tam);
    fflush(stdin);

    if (tam > 5 || tam <= 0) {
        printf("\nQuantidade de eletrodomésticos inválida\n");
    } else {
        for (i = 0; i < tam; i++) {
            printf("\nInsira os dados do seu eletrodoméstico (%d): \n", i + 1);
            printf("O nome: ");
            scanf(" %14[^\n]", c[i].n);

            printf("A potência (em Kw): ");
            scanf("%f", &c[i].p);

            printf("O tempo ativo (em horas): ");
            scanf("%d", &c[i].t);

            ct += c[i].p * c[i].t;
        }

        printf("\nDigite a quantidade de dias: \n");
        scanf("%d", &d);

        
        for (i = 0; i < tam; i++) {
            cr = c[i].p * c[i].t;
            por = (cr / ct) * 100;
            hl = c[i].t * d;

            printf("Nome: %s  |", c[i].n);
            printf(" Tempo: %d horas totais  |", hl);
            printf(" Consumo Relativo: %.2f  \n", por);
        }
    }

    return 0;
}


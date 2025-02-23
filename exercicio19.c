#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

struct V {
    int ori;
    int d;
};

struct A {
    int cod;
    int vs;
    int vc;
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int i;
    int nv = 5; 
    int na = 5; 

    struct V v[nv];
    struct A a[na];

    printf("Início da ação...\n");
    

    for (i = 0; i < na; i++) {
        a[i].cod = i;
        a[i].vs = 0;
        a[i].vc = 0;
    }

    for (i = 0; i < nv; i++) {
        printf("\nDigite o código do aeroporto de origem do voo %d (entre 0 e 4): \n", i + 1);
        scanf("%d", &v[i].ori);
        if (v[i].ori < 0 || v[i].ori > 4) {
            printf("Código inválido... Tente novamente: \n");
            scanf("%d", &v[i].ori);
        }
    

        printf("Digite o código do aeroporto de destino do voo %d (entre 0 e 4): \n", i + 1);
        scanf("%d", &v[i].d);
        if (v[i].d < 0 || v[i].d > 4) {
            printf("Código inválido... Tente novamente: \n");
            scanf("%d", &v[i].d);
        }


        a[v[i].ori].vs++;
        a[v[i].d].vc++;
    }

 	printf("\n -----------------------------\n");
    printf("| Informações dos aeroportos: |");
 	printf("\n -----------------------------\n");
    for (i = 0; i < na; i++) {
        printf(" Aeroporto %d: | Voos que saem: %d | Voos que chegam: %d \n", a[i].cod, a[i].vs, a[i].vc);
    }

    return 0;
}


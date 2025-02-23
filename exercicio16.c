#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct compr {
    char n[60];
    int a;
    int m;
    int d;
};

bool Inserir(int dia, int mes, int ano);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
	
	struct compr c[5];
    int i, me, an, tam;
	
	 printf("Insira quantos compromissos você deseja adicionar (até 5)\n");
	 scanf("%d", &tam);
        fflush(stdin);
        
        if(tam > 5 || tam <= 0){
        	 printf("\nQuantidade de compromissos inválida\n");
		
		}else{
		
    for (i = 0; i < tam; i++) {
        printf("\nInsira os dados do compromisso (%d): \n\n", i + 1);
        printf("O nome: ");
        scanf(" %59[^\n]", c[i].n);
        fflush(stdin);

        printf("O dia: ");
        scanf("%d", &c[i].d);
        fflush(stdin);

        printf("O mês: ");
        scanf("%d", &c[i].m);
        fflush(stdin);

        printf("O ano: ");
        scanf("%d", &c[i].a);
        fflush(stdin);

        if (!Inserir(c[i].d, c[i].m, c[i].a)) {
            printf("\nA data é inválida\n");
            i--; 
            continue;
        }
        printf("\n");
    }
   
    
        printf("\nInsira o mês e o ano do compromisso que deseja procurar: ");
    scanf("%d %d", &me, &an);
    
	
	bool encontrado = false;
    for (i = 0; i < tam; i++) {
        if (c[i].m == me && c[i].a == an) {
        	
		    printf("\nCompromisso: %s |", c[i].n);
		    printf(" Dia: %d |", c[i].d);
            printf(" Ano: %d |", c[i].a);
            printf(" Mês: %d |", c[i].m);
            encontrado = true;
            
        } 
    } 
    if (!encontrado) {
        printf("\nNenhum compromisso agendado para esta data.\n");
   	 }
   	 return 0;
    }
     }
bool Inserir(int dia, int mes, int ano) {

    if (ano < 2000 || ano > 2024) return false;

    if (mes < 1 || mes > 12) return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
    
    if (mes == 2 && dia > 29) return false;
    
    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) return false;

    return true ;

}
    


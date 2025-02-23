#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct pessoa {
    char nome[20];
    int ano;
    int mes;
    int dia;
    char endereco[180];
    char cidade[20];
    char email[180];
    int cep;
};

void imprimir(struct pessoa p);
bool VerificaEmail(char email[180]);
bool Inserir(int dia, int mes, int ano);
bool VerificaCEP(int cep);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct pessoa p;

    printf("Insira o nome: ");
    scanf(" %29[^\n]", p.nome);

    printf("Insira a sua cidade: ");
    scanf(" %19[^\n]", p.cidade);
    printf("Insira o seu CEP (sem o h�fen): ");
    scanf("%d", &p.cep);

    printf("Insira seu dia de Nascimento: ");
    scanf("%d", &p.dia);

    printf("Insira seu m�s de Nascimento: ");
    scanf("%d", &p.mes);

    printf("Insira seu ano de Nascimento: ");
    scanf("%d", &p.ano);

    printf("Insira o endere�o: ");
    scanf(" %[^\n]", p.endereco);

    printf("Insira o e-mail nesse formato (pessoa@gmail.com): ");
    scanf(" %[^\n]", p.email); 

    imprimir(p);

    return 0;
}

bool VerificaEmail(char email[180]) {
    int arroba = 0, ponto = 0;
    int tam = strlen(email);
    int i;

    for (i = 0; i < tam; i++) {
        if (email[i] == '@') arroba++;
        if (email[i] == '.') ponto++;
    }

    return (arroba == 1 && ponto >= 1);
}

bool Inserir(int dia, int mes, int ano) {
    if (ano < 2000 || ano > 2024) return false;
    if (mes < 1 || mes > 12) return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
    if (mes == 2 && dia > 29) return false;
    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) return false;

    return true;
}

bool VerificaCEP(int cep) {

    if (cep < 00000001 || cep > 99999999) return false;
    return true;
}

void imprimir(struct pessoa p) {
    if (!Inserir(p.dia, p.mes, p.ano)) { 
        printf("A data de nascimento � inv�lida.\n");
        return;
    } else {
        printf("\nA data de nascimento � v�lida.\n");    
    }

    if (!VerificaEmail(p.email)) {
        printf("\nE-mail inv�lido! N�o � poss�vel imprimir o cadastro.\n");
        return;
    } else {
        printf("\nO e-mail � v�lido.\n");    
    }

    if (!VerificaCEP(p.cep)) { 
        printf("\nCEP inv�lido! N�o � poss�vel imprimir o cadastro.\n");
        return;
    } else {
        printf("\nCEP v�lido.\n");        
    }
    
    printf("\n- Cadastro -\n\n");
    printf(" Nome: %s |", p.nome);
    printf(" Data de Nascimento: %02d/%02d/%d |", p.dia, p.mes, p.ano);
    printf(" E-mail: %s |", p.email);
    printf(" Cidade: %s |", p.cidade);
    printf(" CEP: %05d-%03d |", p.cep / 1000, p.cep % 1000);
    printf(" Endere�o: %s\n", p.endereco);
    printf("\n---------------------\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

typedef struct Row {
    int ini, fim;
    char f[MAX];
} Fila;

bool cheia(Fila f1) {
    return f1.fim == MAX - 1;
}

bool vazia(Fila f1) {
    return f1.fim == f1.ini - 1;
}

Fila insere(Fila f1, char item) {
    f1.fim++;
    f1.f[f1.fim] = item;
    return f1;
}

void exibe(Fila f1) {
    for (int i = f1.ini; i <= f1.fim; i++) {
        printf("%c ", f1.f[i]);
    }
    printf("\n");
}

int ehVogal(char c) {
    c = (c >= 'a' && c <= 'z') ? c : (c + 'a' - 'A');
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    Fila filaVogais, filaConsoantes;
    char resp;

    filaVogais.ini = 0;
    filaVogais.fim = -1;
    filaConsoantes.ini = 0;
    filaConsoantes.fim = -1;

    setlocale(LC_ALL, "Portuguese");

    while (1) {
    	system("cls");
        printf("Digite um caractere (digite ponto para finalizar): ");
        scanf(" %c", &resp);

        if (resp == '.') {
            break;
        }
        
         if (ehVogal(resp)) {
            filaVogais = insere(filaVogais, resp);
        } else {
            filaConsoantes = insere(filaConsoantes, resp);
        }
    }

	system("cls");
	
    printf("Fila de vogais: ");
    exibe(filaVogais);
    

    printf("\n\nFila de consoantes: ");
    exibe(filaConsoantes);
    

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

typedef struct Stack {
    int topo;
    char p[MAX];
} Pilha;

int cheia(Pilha p1) {
    return p1.topo == MAX - 1;
}

int vazia(Pilha p1) {
    return p1.topo == -1;
}

Pilha empilha(Pilha p1, char item) {
    if (!cheia(p1)) {
        p1.topo++;
        p1.p[p1.topo] = item;
    }
    return p1;
}

Pilha desempilha(Pilha p1) {
    if (!vazia(p1)) {
        p1.topo--;
    }
    return p1;
}

char topo(Pilha p1) {
    if (!vazia(p1)) {
        return p1.p[p1.topo];
    }
    return '\0';
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    p1.topo = -1;
    
    char str[MAX];
    int i, j;
    
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        p1 = empilha(p1, str[i]);
    }
  
    for (j = 0, i = p1.topo; i >= 0; i--, j++) {
        if (str[j] != p1.p[i]) {
            printf("\nA string nao e um palindromo!\n");
            return 0;
        }
    }
    
    printf("\nA string e um palindromo!\n");
    return 0;
}

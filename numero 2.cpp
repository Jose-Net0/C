#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct Stack {
    int topo;
    char p[MAX];
} Pilha;

bool cheia(Pilha p1) {
    return p1.topo == MAX - 1;
}

bool vazia(Pilha p1) {
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

bool ehVogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    char str[MAX];
    Pilha vogais;
    vogais.topo = -1;
    char saida[MAX];
    int num = 0;
    
    printf("Digite uma string:  ");
    scanf("%s", str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (ehVogal(str[i])) {
            vogais = empilha(vogais, str[i]);
        } else {
            saida[num++] = str[i];
        }
    }
    
    while (!vazia(vogais)) {
        saida[num++] = topo(vogais);
        vogais = desempilha(vogais);
    }
    
    saida[num] = '\0';
    
    printf("Criptografada: %s\n", saida);
    
    return 0;
}


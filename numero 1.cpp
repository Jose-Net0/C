#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

typedef struct Stack {
    int topo;
    char p[MAX];
} Pilha;

bool cheia(Pilha p1){
    if(p1.topo == MAX-1)
       return true;   
    else
       return false;   
}

bool vazia(Pilha p1){
    if(p1.topo == -1)
       return true;    
    else
       return false;   
}

Pilha empilha(Pilha p1, int item){
    p1.topo++;
    p1.p[p1.topo] = item;
    return p1;
}

Pilha desempilha(Pilha p1){
    p1.topo--;
    return p1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    p1.topo = -1;
    
    char str[MAX];
    int i;
    
    printf("Digite uma palavra: ");
    scanf("%9s", str);
    
    for (i = 0; str[i] != '\0'; i++) {
        if (cheia(p1)) {
            printf("Limite da pilha atingido!\n");
            break;
        }
        p1 = empilha(p1, str[i]); 
    }
  
    printf("\nOrdem contrária: ");
    while (!vazia(p1)) {
        printf("%c", p1.p[p1.topo]);
        p1 = desempilha(p1);
    }
    printf("\n");
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define QUANTUM 2

typedef struct Processo {
    int pid; 
    int prioridade;
    int ts; 
} Processo;

typedef struct No {
    Processo processo;
    int tempoRestante;
    struct No* proximo;
    struct No* anterior;
} No;

struct No* criaNo(Processo processo) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->processo = processo;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    return novoNo;
}

void insereOrdenado(struct No* head, Processo processo) {
    struct No* novoNo = criaNo(processo);
    struct No* temp = head;
    if(head==NULL){
        head->proximo = novoNo;
    }
    else{
        while(novoNo->processo.prioridade > temp->proximo->processo.prioridade && temp->proximo != NULL){
            temp = temp->proximo;
        }
        
    }


}


int main (){
    // Inicializa a lista como vazia
    struct No* head = NULL;


return 0;
}





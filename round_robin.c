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
    int prioridade;
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

void insereNaLista(struct No** head, Processo processo) {
    struct No* novoNo = criaNo(processo);
    if (*head == NULL) {
        *head = novoNo;
    } 
    else {
        struct No* temp = *head;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
        novoNo->anterior = temp;

    }
}


void organizaPorPrioridade(No** head) {
   // TO DO!!
}

void printaLista(struct No* head) {
    struct No* temp = head;
    while (temp != NULL) {
        printf("PID: %d, Prioridade: %d, Tempo de Serviço: %d\n", temp->processo.pid, temp->processo.prioridade, temp->processo.ts);
        temp = temp->proximo;
    }
}


int main (){
    struct No* head = NULL;
   
    // Adiciona 3 processos à lista
    Processo processo1 = {1, 3, 10};
    Processo processo2 = {2, 1, 8};
    Processo processo3 = {3, 2, 12};

    insereNaLista(&head, processo1);
    insereNaLista(&head, processo2);
    insereNaLista(&head, processo3);

    printf("Lista antes de organizar por prioridade:\n");
    imprimeLista(head);

    organizaPorPrioridade(head);

    printf("\nLista depois de organizar por prioridade:\n");
    printaLista(head);


return 0;
}





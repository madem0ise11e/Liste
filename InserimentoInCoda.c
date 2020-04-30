#include <stdio.h>
#include <stdlib.h>
//al momento non ho ancora allocato memoria per una struct
struct elem {
    int mat;
    //qui posso inserire quanti campi voglio e di qualunque tipo
    struct elem *next;
};

struct elem *addInTesta(struct elem *top, int i);
struct elem *addInCoda(struct elem *top, int i);
void stampaLista( struct elem* top);
int main() {
    int i=0, n=0;
    //la lista più piccola che potete creare, cioè una lista vuota
    //ho allocato la memoria in maniera automatica solo per il puntatore
    struct elem *top1=NULL, *top2=NULL;
    //************************************************************
    printf("Quanti elementi vuoi aggiungere? ");
    scanf("%d", &n);
    for(i=0; i<n; ++i){
        top1 = addInTesta(top1,i); //passo (d)
        top2 = addInCoda(top2,i); //passo (d)

    }
    printf("stampa Lista in testa");
    stampaLista(top1);
    printf("stampa Lista in coda");
    stampaLista(top2);
return 0;
}

struct elem *addInTesta(struct elem *t, int i){
    struct elem *tmp=(struct elem *) malloc(sizeof(struct elem)); //passo (b)
    tmp->mat=i;
    tmp->next=t; //passco (c)
    t=tmp;
    return t;
}

struct elem *addInCoda(struct elem *top, int i){
    struct elem *tmp=(struct elem *) malloc(sizeof(struct elem)); //passo (b)
    tmp->mat=i;
    struct elem *c;
    if (top==NULL){
        tmp->next=top;
        top=tmp; // restituisco il nuovo top
    } else {
        c=top; //sicuramente c !=NULL
        while(c->next!=NULL) c=c->next;
        c->next=tmp;
        tmp->next=NULL;
    }
    return top;
}

void stampaLista( struct elem* top){
    struct elem *tmp;
    tmp=top;
    printf("\nStampa Lista:\n");
    while(tmp!=NULL){ //sono sicura che all'interno del while tmp e' diverso da NULL
                      //in modo tale da poter accedere ai campi!!!
    printf("%d\n", tmp->mat);
    tmp=tmp->next;
    }
}

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 20

struct studente {
  char cognome[MAXLEN];
  char nome[MAXLEN];
  int matricola[MAXLEN];
  float mediaVoti[MAXLEN];
  struct studente *next;
};

struct studente *insInTesta(struct studente *top);
void stampaLista(struct studente *top);

int main(){
  int n,i;
  struct studente *top;
  top=NULL; //una lista vuota
  printf("Quanti elementi vuoi inserire? ");
  scanf("%d", &n);
  for(i=0; i<n; ++i){
    top = insInTesta(top);
  }
  stampaLista(top);
return 0;
}

struct studente *insInTesta(struct studente *top){
  //alloco memoria in maniera dinamica
  struct studente *tmp=(struct studente *)malloc(sizeof(struct studente));
  //inserisco le informazioni
  printf("\nDammi cognome: ");
  scanf("%s", tmp->cognome);
  printf("Dammi nome: ");
  scanf("%s", tmp->nome);
  printf("Dammi matricola: ");
  scanf("%d", tmp->matricola);
  printf("Dammi media voti: ");
  scanf("%f", tmp->mediaVoti);
  //inserisco in testa
  tmp->next=top;
  top=tmp;
  return top;
}

void stampaLista(struct studente *top){
  struct studente *tmp;
  tmp=top;
  printf("\nStampa Lista: \n");
  while(tmp!=NULL){
    printf("%s %s %d %f\n", tmp->cognome, tmp->nome, tmp->matricola, tmp->mediaVoti);
    tmp=tmp->next;
  }
}

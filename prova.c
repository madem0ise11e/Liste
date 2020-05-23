#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 20

struct studente {
  char cognome[MAXLEN];
  char nome[MAXLEN];
  int matricola;
  float mediaVoti;
  struct studente *next;
};

struct studente *insInTesta(struct studente *top);
struct studente *addInCoda(struct studente *top2);
void stampaLista(struct studente *top);

int main(){
  int n,i,scelta;
  struct studente *top;
  struct studente *top2;
  top=NULL; //una lista vuota

 do {
  printf("\n\n***** Menu a scelta *****\n1.Inserisci in testa.\n2.Insersci in coda.\n3.Stampa lista (testa).\n4.Stampa lista (coda).\n0.Uscita.\n");
  printf("Inserisci la scelta: ");
  scanf("%d", &scelta);
    switch(scelta){
      case 1:
      printf("Quanti elementi vuoi inserire? ");
      scanf("%d", &n);
      for(i=0; i<n; ++i){
      top = insInTesta(top);
      }
      break;
      case 2:
      printf("Quanti elementi vuoi inserire? ");
      scanf("%d", &n);
      for(i=0; i<n; ++i){
        top2 = addInCoda(top2);
      }
      break;
      case 3:
      stampaLista(top);
      break;
      case 4:
      stampaLista(top2);
      break;
      case 0:
      printf("Uscita.");
      break;
      default:
      printf("Scelta non coretta!");
  }
} while (scelta!=0);
return 0;
}

struct studente *insInTesta(struct studente *top){
  //alloco memoria in maniera dinamica
  struct studente *tmp=(struct studente *)malloc(sizeof(struct studente));
  //inserisco le informazioni
  printf("\nInserisci in testa.");
  printf("\nDammi cognome: ");
  scanf("%s", tmp->cognome);
  printf("Dammi nome: ");
  scanf("%s", tmp->nome);
  printf("Dammi matricola: ");
  scanf("%d", &(tmp->matricola));
  printf("Dammi media voti: ");
  scanf("%f", &(tmp->mediaVoti));
  //inserisco in testa
  tmp->next=top;
  top=tmp;
  return top;
}

struct studente *addInCoda(struct studente *top2){
    struct studente *tmp=(struct studente *) malloc(sizeof(struct studente)); //passo (b)
    printf("\nInserisci in coda.");
    printf("\nDammi cognome: ");
    scanf("%s", tmp->cognome);
    printf("Dammi nome: ");
    scanf("%s", tmp->nome);
    printf("Dammi matricola: ");
    scanf("%d", &(tmp->matricola));
    printf("Dammi media voti: ");
    scanf("%f", &(tmp->mediaVoti));
    struct studente *c;
    //inserisco in coda
    if (top2==NULL){
      tmp->next=top2;
      top2=tmp; // restituisco il nuovo top
    } else {
      c=top2; //sicuramente c !=NULL
      while(c->next!=NULL) c=c->next;
      c->next=tmp;
      tmp->next=NULL;
    }
    return top2;
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

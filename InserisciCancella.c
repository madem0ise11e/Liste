#include <stdio.h>
#include <stdlib.h>

struct studente {
  char cognome;
  struct studente *nextPtr;
};

void inserisci(struct studente *s, char value);
char elimina(struct studente *s, char value);
int seVuoto(struct studente s);
void stampaLista(struct studente correntePtr);
void istruzioni(void);

int main(void){
  struct studente primoPtr = NULL;
  unsigned int scelta;
  char voce;

  istruzioni();
  printf("%s", "? ");
  scanf("%u", &scelta);
  while(scelta != 3){
    switch(scelta){
      case 1:
        printf("%s", Inserisci il cognome: );
        scanf("\n%s", &voce);
        inserisci(&primoPtr, voce);
        stampaLista(primoPtr);
        break;
      case 2:
        if(!seVuoto(primoPtr)){
          printf("%s", Inserisci il cognome da cancellare: );
          scanf("\n%s", &voce);
        }
        break;
      default:
          puts("Invalid choice.\n");
          istruzioni();
          break;
    } //fine di switch

  printf("%s", "? ");
  scanf("%u", &scelta);
  }//fine di while

  puts(Fine di esecuzione);
}//fine del main

void istruzioni(void){
  puts("Metti la tua scelta: \n"
        "  1 per inserire cognome nella lista.\n"
        "  2 per cancellare cognome dalla lista.\n"
        "  3 per uscire.");
}

void inserisci(struct studente *s, char value){
  struct studente nuovoPtr; //puntatore al nuovo no
  struct studente precedentePtr; //puntatore al nodo precedente nella lista
  struct studente correntePtr; //puntatore al nodo corrente nella lista

  nouvoPtr = malloc(sizeof(struct studente)); //crea il nodo

  if(nuovoPtr != NULL){ //se c'è spazio disponibile
    nuovoPtr->cognome = value; //inserisci value nel nodo
    nuovoPtr->nextPtr = NULL; //il nodo non è collegato ad altri nodi

    precedentePtr = NULL;
    correntePtr = *s;

    //ripeti il ciclo per trovare la posizione corretta nella lista
    while (correntePtr != NULL && value > correntePtr->cognome){
      precedentePtr = correntePtr; //va avanti..
      correntePtr = correntePtr->nextPtr; //..al nodo successivo
    } //fine di while

    //inseri il nuovo nodo all'inizio della lista
    if(precedentePtr == NULL){
      nuovoPtr->nextPtr = *s;
      *s = nuovoPtr;
    } //fine di if
    else { //inserisci il nuovo nodo tra precedentePtr e correntePtr
      precedentePtr->nextPtr = nuovoPtr;
      nuovoPtr->nextPtr = correntePtr;
    } //fine di else
  } //fine di if
  else {
    printf("%s non e' stato inserito. Non c'e memoria disponibile.\n", value);
  } //fine di else
} //fin della funzione inserisci

char elimina(struct studente *s, char value){

}

//restituisci 1 se la lista e' vuota, altrimenti 0
int seVuoto(struct studente s) {
  return s == NULL;
}

//stampa la lista
void stampaLista(struct studente correntePtr){
  //se la lista e vuota
  if(seVuoto(correntePtr)){
    puts("Lista e' vuota.\n");
  } //fine di if
  else {
    puts("Lista e': ");

    //finche non si raggiunge la fine della lista
    while(correntePtr != NULL) {
      printf("%s --> ", correntePtr->cognome);
      correntePtr = correntePtr->nextPtr;
    } //fine di while

    puts("NULL\n");
  } //fine di else
} //fine di funzione stampaLista

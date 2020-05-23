//LISTE DOPPIAMENTE COLLEGATE CON ELEMENTO FITTIZIO
#include <stdio.h>
#include <stdlib.h>

struct elem {
	int k;
	struct elem *pre;
	struct elem *next;
};

struct elem *newLista();
void inserisciInOrdine(struct elem *lista);
void stampaLista(struct elem *lista);
void eliminaMinoridiK(struct elem *lista, int k);
int main() {

	// UN MAIN CHE FA CREARE DALL'UTENTE UNA LISTA ORDINATA DI n ELEMENTI,
	// DOPODICHE' L'UTENTE PUO' SCEGLIERE SE ELIMINARE GLI ELEMENTI MINORE DI k,
	//OPPURE STAMPARE LA LISTA, OPPURE INSERIRE UN NUOVO ELEMENTO, OPPURE
	//USCIRE DAL PROGRAMMA
	//prima di uscire ELIMINARE L'INTERA LISTA

}
struct elem *newLista(){
	return NULL;
}
void inserisciInOrdine(struct elem *lista){
}
void stampaLista(struct elem *lista){
}
void eliminaMinoridiK(struct elem *lista, int k){
}

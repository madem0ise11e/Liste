#include <stdio.h>
#include <stdlib.h>

struct elem *insInOrdine(struct elem *top, int k);
void stampaLista(struct elem *top);

int main(){
  for(){
    printf("");
    scanf("%d", &k);
  top =insInOrdine(top,k);
  }
  stampaLista(top);
}

struct elem *insInOrdine(struct elem *top, int k){
  struct elem *s, *p;
  tmp=(struct elem*)malloc(sizeof(struct elem));
  tmp->k=k;
  tmp->next=NULL;
  s=top;
  p=NULL;
  while(s!=NULL && s->k<k) {
  p=s;
  s= s->next;
  }
  tmp->next=s;
  if(p==NULL)
  top=tmp;
  else
  p->next=tmp;
  }
  return top;
}

void stampaLista(struct elem *top){
  while(top!=NULL){
    printf("%d\n", top->k);
    top=top->next;
  }
}

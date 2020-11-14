#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Arvore;

/* Função que cria uma árvore */
Arvore* createArvore()
{
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int ArvoreIsEmpty(Arvore* t)
{
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void mostraArvore(Arvore* t)
{
  /* Essa função imprime os elementos de forma recursiva */
  
  printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!ArvoreIsEmpty(t)) 
  {
    /* Mostra os elementos em pré-ordem */
    printf("%d ", t->num); /* mostra a raiz */
    mostraArvore(t->sae); /* mostra a sae (subárvore à esquerda) */
    mostraArvore(t->sad); /* mostra a sad (subárvore à direita) */
  }
  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void insertArvore(Arvore** t, int num)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Arvore*)malloc(sizeof(Arvore)); /* Aloca memória para a estrutura */
    (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
    (*t)->sad = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      insertArvore(&(*t)->sae, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      insertArvore(&(*t)->sad, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInArvore(Arvore* t, int num) {
  
  if(ArvoreIsEmpty(t)) { 
    return 0;
  }
  
  return t->num==num || isInArvore(t->sae, num) || isInArvore(t->sad, num);
}

int main()
{
  Arvore* t = createArvore(); /* cria uma árvore */
  
  insertArvore(&t, 14); 
  insertArvore(&t, 15); 
  insertArvore(&t, 4); 
  insertArvore(&t, 9); 
  insertArvore(&t, 7);
  insertArvore(&t, 18);
  insertArvore(&t, 3);
  insertArvore(&t, 5);
  insertArvore(&t, 16); 
  insertArvore(&t, 4);
  insertArvore(&t, 20);
  insertArvore(&t, 17);
  insertArvore(&t, 9);
  insertArvore(&t, 14);
  insertArvore(&t, 5);
   
  mostraArvore(t); /* Mostra os elementos da árvore em pré-ordem */
  
  if(ArvoreIsEmpty(t)) /* Verifica se a árvore está vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }
  
  if(isInArvore(t, 15)) { /* Verifica se o número 15 pertence a árvore */
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }
  
  if(isInArvore(t, 22)) { /* Verifica se o número 22 pertence a árvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }
  
  free(t); /* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}


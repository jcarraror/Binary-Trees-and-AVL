#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node  
{ 
  int inf; 
  struct Node *right; 
  struct Node *left; 
}node;

/*
Pre Ordem = Raiz Esqueda Direita
ORDEM =   Esquerda raiz direita
Pos ordem = Esquerda Direita Raiz
*/

node* Inicia(){
    return NULL;
}

node* Inserir(node* arv, int dado){
    
	if(arv==NULL){
		node *t=(node*)malloc(sizeof(node));   
        t->inf=dado;
        t->right=NULL;
        t->left=NULL;
        return t;
    }
	if (dado < arv->inf)
		arv->left = Inserir(arv->left,dado);
	if(dado > arv->inf)
		arv->right = Inserir(arv->right,dado);   
	return(arv); 
}

int Vazia(node* arv){
	return arv==NULL;
    
}

void EmOrdem(node* arv){
    printf("-- ");
    if(!Vazia(arv)){	
        EmOrdem(arv->left);
        printf("\n %d",arv->inf);
        EmOrdem(arv->right);
    }
    printf(" --\n");
}
void PreOrdem(node* arv){
    printf("-- ");
    if(!Vazia(arv)){
        printf("\n %d",arv->inf);
        PreOrdem(arv->left);
        PreOrdem(arv->right);
    }
    printf(" --\n");
}
void PosOrdem(node* arv){
    printf("-- ");
    if(!Vazia(arv)){
        PosOrdem(arv->left);
        PosOrdem(arv->right);
        printf("\n %d",arv->inf);
    }
    printf(" --\n");
}
        
int menu(){
    int aux;
    int chute;
    bool ff=false;
    while(ff==false) {

        printf("Opcoes: \n\n");
        printf("1 - Criar a arvore\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Buscar elemento\n");
        printf("5 - Mostrar Em Ordem\n");
        printf("6 - Mostrar Pos Ordem\n");
        printf("7 - Mostrar Pre-Ordem\n");
        printf("8 - Desalocar\n");
        printf("9 - Mostrar a arvore em formato de arvore\n");
        
        scanf("%d",&aux);
        if(aux<1 || aux>9){
            system("clear");
            printf("Coloque um numero valido");
            printf("\n\n\nPress any key...");
            getchar();
            getchar();
            system("clear");
        }else{
            ff=true;
        }
    }
    return aux;
}

int main(){
  int opcao, x,y;
  bool existe=false;
    node *Arvore=(node*)malloc(sizeof(node));	
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: if(existe==false){
					    Arvore=Inicia();
					    existe=true;
			        }else{
			           printf("\n\nJa¡ existe uma arvore criada, utilize a!!\n\n ");
			        }   
			        //
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					Arvore = Inserir(Arvore,x);
					//
					break;
			case 3: printf("Elemento a ser removido: ");
					scanf("%d",&x);
					//
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					//
					break;
			case 5: EmOrdem(Arvore);
					break;
			case 6: PosOrdem(Arvore);
					break;
			case 7: PreOrdem(Arvore);
					break;
			case 8: //
					break;
			case 9: //
					break;
			} 
	}while(opcao !=0);
}


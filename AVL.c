#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
	int num;
	struct arv *esq, *dir;
	int altura;
} arv;

arv *insere(arv *, int);
arv *exclui(arv *, int);
void mostraPreOrdem(arv *);
void mostraEmOrdem(arv *);
void mostraPosOrdem(arv *);
void mostraArvore(arv *, int);
int altura(arv *);
arv *rotacionaDir(arv *);
arv *rotacionaEsq(arv *);
arv *RR(arv *);
arv *LL(arv *);
arv *LR(arv *);
arv *RL(arv *);
int balanceia(arv *);
arv *buscar(arv *, int);
arv *desalocar(arv *);

int main()
{
	struct arv *raiz = (struct arv *)malloc(sizeof(struct arv));
	raiz = NULL;
	int x, op;

	do
	{
		printf("1 - Criar a arvore\n");
		printf("2 - Inserir\n");
		printf("3 - Remover\n");
		printf("4 - Buscar elemento\n");
		printf("5 - Mostrar Em Ordem\n");
		printf("6 - Mostrar Pos Ordem\n");
		printf("7 - Mostrar Pre-Ordem\n");
		printf("8 - Desalocar\n");
		printf("9 - Desafio >> Mostrar arvore em formato de arvore\n");
		printf("0 - Sair\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			printf("\nInsira o nodo raiz para criar a arvore:");

			raiz = NULL;

			scanf("%d", &x);
			raiz = insere(raiz, x);

			break;

		case 2:
			printf("\nInsira o numero:");
			scanf("%d", &x);
			raiz = insere(raiz, x);
			break;

		case 3:
			printf("\nInforme o numero para remocao:");
			scanf("%d", &x);
			raiz = exclui(raiz, x);
			break;

		case 4:
			printf("\nInforme o numero para busca:");
			scanf("%d", &x);
			buscar(raiz, x);
			break;

		case 5:

			mostraEmOrdem(raiz);
			printf("\n");
			break;

		case 6:

			mostraPosOrdem(raiz);
			printf("\n");
			break;

		case 7:

			mostraPreOrdem(raiz);
			printf("\n");
			break;

		case 8:
			raiz = desalocar(raiz);

		case 9:
			mostraArvore(raiz, 0);
			break;
		}
	} while (op != 0);

	return 0;
}

//inserir
arv *insere(arv *raiz, int x)
{
	if (raiz == NULL)
	{
		raiz = (arv *)malloc(sizeof(arv));
		raiz->num = x;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	else if (x > raiz->num)
	{
		raiz->dir = insere(raiz->dir, x);
		if (balanceia(raiz) == -2)
			if (x > raiz->dir->num)
				raiz = RR(raiz);
			else
				raiz = RL(raiz);
	}
	else if (x < raiz->num)
	{
		raiz->esq = insere(raiz->esq, x);
		if (balanceia(raiz) == 2)
			if (x < raiz->esq->num)
				raiz = LL(raiz);
			else
				raiz = LR(raiz);
	}

	raiz->altura = altura(raiz);

	return (raiz);
}

//buscar
arv *buscar(struct arv *raiz, int x)
{
	if (raiz == NULL)
		return NULL;
	else if (raiz->num > x)
		return buscar(raiz->esq, x);
	else if (raiz->num < x)
		return buscar(raiz->dir, x);
	else
		printf("Elemento encontrado\n");
}

//desalocar
arv *desalocar(arv *raiz)
{
	if (raiz != NULL)
	{
		desalocar(raiz->esq);
		raiz->esq = NULL;
		desalocar(raiz->dir);
		raiz->dir = NULL;
		free(raiz);
		raiz = NULL;
		return 0;
	}
}

//excluir nodos
arv *exclui(arv *raiz, int x)
{
	arv *p;

	if (raiz == NULL)
	{
		return NULL;
	}
	else if (x > raiz->num)
	{
		raiz->dir = exclui(raiz->dir, x);
		if (balanceia(raiz) == 2)
			if (balanceia(raiz->esq) >= 0)
				raiz = LL(raiz);
			else
				raiz = LR(raiz);
	}
	else if (x < raiz->num)
	{
		raiz->esq = exclui(raiz->esq, x);
		if (balanceia(raiz) == -2)
			if (balanceia(raiz->dir) <= 0)
				raiz = RR(raiz);
			else
				raiz = RL(raiz);
	}
	else
	{

		if (raiz->dir != NULL)
		{
			p = raiz->dir;

			while (p->esq != NULL)
				p = p->esq;

			raiz->num = p->num;
			raiz->dir = exclui(raiz->dir, p->num);

			if (balanceia(raiz) == 2)
				if (balanceia(raiz->esq) >= 0)
					raiz = LL(raiz);
				else
					raiz = LR(raiz);
		}
		else
			return (raiz->esq);
	}
	raiz->altura = altura(raiz);
	return (raiz);
}

//calcula altura da arvore para auxiliar as funções de inserir e excluir
int altura(arv *raiz)
{
	int alturaesq, alturadir;
	if (raiz == NULL)
		return (0);

	if (raiz->esq == NULL)
		alturaesq = 0;
	else
		alturaesq = 1 + raiz->esq->altura;

	if (raiz->dir == NULL)
		alturadir = 0;
	else
		alturadir = 1 + raiz->dir->altura;

	if (alturaesq > alturadir)
		return (alturaesq);

	return (alturadir);
}

//função auxiliar de rotação direita
arv *rotacionaDir(arv *x)
{
	arv *y;
	y = x->esq;
	x->esq = y->dir;
	y->dir = x;
	x->altura = altura(x);
	y->altura = altura(y);
	return (y);
}

//função auxiliar de rotação esquerda
arv *rotacionaEsq(arv *x)
{
	arv *y;
	y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	x->altura = altura(x);
	y->altura = altura(y);

	return (y);
}

//função principal que chama a função auxiliar de rotação
arv *RR(arv *raiz)
{
	raiz = rotacionaEsq(raiz);
	return (raiz);
}

//função principal que chama a função auxiliar de rotação
arv *LL(arv *raiz)
{
	raiz = rotacionaDir(raiz);
	return (raiz);
}

//função principal que chama a função auxiliar de rotação
arv *LR(arv *raiz)
{
	raiz->esq = rotacionaEsq(raiz->esq);
	raiz = rotacionaDir(raiz);

	return (raiz);
}

//função principal que chama a função auxiliar de rotação
arv *RL(arv *raiz)
{
	raiz->dir = rotacionaDir(raiz->dir);
	raiz = rotacionaEsq(raiz);
	return (raiz);
}

//função de balanceio para auxiliar as funções de rotação, inclusão e exclusão de nodos
int balanceia(arv *raiz)
{
	int alturaesq, alturadir;
	if (raiz == NULL)
		return (0);

	if (raiz->esq == NULL)
		alturaesq = 0;
	else
		alturaesq = 1 + raiz->esq->altura;

	if (raiz->dir == NULL)
		alturadir = 0;
	else
		alturadir = 1 + raiz->dir->altura;

	return (alturaesq - alturadir);
}

//mostrar
void mostraPreOrdem(arv *raiz)
{
	if (raiz != NULL)
	{
		printf(" %d ", raiz->num);
		mostraPreOrdem(raiz->esq);
		mostraPreOrdem(raiz->dir);
	}
}

//mostrar
void mostraArvore(struct arv *raiz, int espacamento)
{
	int i;
	if (raiz != NULL)
	{
		mostraArvore(raiz->dir, espacamento + 2);
		for (i = 0; i < espacamento; i++)
			printf(" -- ");
		printf("%d\n", raiz->num);
		mostraArvore(raiz->esq, espacamento + 2);
	}
}

//mostrar
void mostraPosOrdem(struct arv *raiz)
{
	if (raiz != NULL)
	{
		mostraPosOrdem(raiz->esq);
		mostraPosOrdem(raiz->dir);
		printf(" %d ", raiz->num);
	}
}

//mostrar
void mostraEmOrdem(arv *raiz)
{
	if (raiz != NULL)
	{
		mostraEmOrdem(raiz->esq);
		printf(" %d",raiz->num);
		mostraEmOrdem(raiz->dir);
	}
}
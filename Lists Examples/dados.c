#include "dados.h"
#include <stdio.h>

int igual(data_t d1,data_t d2)
{
	if(d1.cod==d2.cod)
		return 1;
	else
		return 0;
}

void inserir_dados(data_t *d1)
{

	printf("Indique o codigo do aluno:");
	scanf("%d",&(d1->cod));
	fflush(stdin);
	printf("Indique o nome do aluno:");
	gets(d1->nome);
	printf("Indique a nota do aluno:");
	scanf("%f",&(d1->nota));
}

void mostrar_dados(data_t d1)
{

	printf("Codigo de aluno: %d\n",d1.cod);
	printf("Nome do aluno: %s \n",d1.nome);
	printf("Nota: %f \n",d1.nota);
}

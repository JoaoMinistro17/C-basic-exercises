#include <stdio.h>
#include <stdlib.h>

typedef struct clientes 
{
    int codigo;
    char nome[50];
    char morada[50];
    int saldo_global;
    struct clientes *prox;
}Cliente;

typedef struct contas_clientes 
{
    int codigo;
    char tipo[50];
    int saldo;
    struct contas_clientes *prox;
}Conta;

void clientesLoc (Cliente **ListaClientes, char *localidade)
{
    Cliente *aux;
	aux = *ListaClientes;

    if (aux){
        while (aux){
            if (strcmp(aux->morada, localidade) == 0){
                printf("Codigo: %d \nNome: %s\n", aux->codigo, aux->nome);
            }
        aux = aux->prox;
        } 
    } else {
        printf("Lista de clientes da localidade vazia!\n");
    }
}

int saldoTotal (Conta *ListaContas)
{
    int saldoTotal;

    if (ListaContas){ 
        while (ListaContas){
            saldoTotal += ListaContas->saldo; 
            ListaContas = ListaContas->prox;           
        } 
    } else {
        printf("Lista de contas vazia!\n");
    }
    return saldoTotal;
}

void clientesSaldoNeg(Cliente *ListaClientes)
{
    if (ListaClientes){ 
        while (ListaClientes){
            if (ListaClientes->saldo_global < 0){
                printf("Codigo: %d \nNome: %s\n", ListaClientes->codigo, ListaClientes->nome);
            }
			ListaClientes = ListaClientes->prox;           
        } 
    } else {
        printf("Lista de clientes com saldo negativo vazia!\n");
    }
}

void addListaCli(Cliente* novo_cli, Cliente** ListaClientes){ 
    if ((*ListaClientes) == NULL) { 			
        (*ListaClientes) = novo_cli; 			
    } else { 								
        novo_cli->prox = (*ListaClientes);  
        (*ListaClientes) = novo_cli;			
    }
}

void mostrarListaCli (Cliente* ListaClientes){	
	if (ListaClientes){ 
        while (ListaClientes){
            printf(("\n\nCodigo: %d \nNome: %s\nMorada: %s\n\n"), ListaClientes->codigo, ListaClientes->nome, ListaClientes->morada);
			ListaClientes = ListaClientes->prox;           
        } 
    } else {
        printf("Lista de clientes vazia!\n");
    }
}

Cliente *novoCliente (int *i_cli){
	
	Cliente* novo_cli = (Cliente*)malloc(sizeof(Cliente));
	
	printf("\nNome: ");
	gets(novo_cli->nome);

	printf("\nMorada: ");
	gets(novo_cli->morada);
	
	novo_cli->codigo = (*i_cli);
	(*i_cli)++;
	novo_cli->saldo_global = 0;
	novo_cli->prox = NULL;
	
	return novo_cli;
}	

int main()
{
    Cliente *ListaClientes = NULL;
    Cliente *novo_cli = NULL;
    Conta *ListaContas = NULL;
    char localidade[5] = "braga";
	int saldo, i_cli = 1;
    
	novo_cli = novoCliente (&i_cli);
	addListaCli(novo_cli, &ListaClientes);
	mostrarListaCli (ListaClientes);
	
    clientesLoc (&ListaClientes, localidade);
    saldo = saldoTotal (ListaContas);
    clientesSaldoNeg (ListaClientes);
    
    return 0;
}
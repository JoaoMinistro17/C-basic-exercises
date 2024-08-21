typedef struct produtos {
	int cod;
	char nome[50];
	float nota;
} data_t;

int igual(data_t d1,data_t d2);

void inserir_dados(data_t *d1);

void mostrar_dados(data_t d1);


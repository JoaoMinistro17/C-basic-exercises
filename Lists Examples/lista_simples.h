typedef struct node {
    data_t data;
    struct node* next;
} node_t;

node_t * criar_nodo(data_t d1);

void inserirInicio(node_t **lista, data_t d1);

void inserirFim(node_t **lista, data_t d1);

void inserirFim2(node_t **lista, node_t **fim, data_t d1);

int removerElemento(node_t **lista, data_t valorProcurado);

void listar(node_t *lista);

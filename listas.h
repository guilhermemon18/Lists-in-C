#define TipoItem int
//estrutura de no para lista encadeada
typedef struct no {
    int info;
    struct no *prox;
} Lista;

int vazia(Lista *l);
Lista* inserir(Lista* l, int info);
Lista* remover(Lista* l, int info);
void imprimir(Lista* l);
Lista* copiar(Lista* copia);
Lista* inverter(Lista* l);
Lista* FindUltimo(Lista* l);
Lista* concatenar(Lista* l1, Lista* l2);
Lista* intercalar(Lista* l1, Lista* l2);
Lista* append(Lista* l1, Lista* l2);
int conta_ocorrencias(Lista* l,int x) ;
Lista* elimina_repetidos(Lista* l);
Lista* pares(Lista* l);
int elementosLista(Lista* l);
Lista* ordenar(Lista* l);
Lista* busca(Lista* l, TipoItem info);

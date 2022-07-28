#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//testa se uma lista � vazia
//Entrada: lista
//Retorno: 1se lista � vazia ou 0 caso contr�rio
//pre condi�ao : nennhuma
//P�s-condi�ao : nenhuma
int vazia(Lista *l) {
    return (l == NULL);
}

//insere um eleemento na lista
//Entrada: llista e elemento a ser inserido
//Retorno: lista alterada
//Pr�-condi��o: nenhuma
//P�s_condi��o: elemento � inserido na lista.
Lista* inserir(Lista* l, int info) {
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;
    return aux;//l = inserir(l, 50); exemplo de chmada de fun��o
}

//Remove um elemento da lista
//entrada: listae elemento a ser removido
//retorno: lista alterada
//pr�_condi�ao: nenhuma
//P�s-condi��o: elemento e removido da lista.
Lista* remover(Lista* l, int info) {
    Lista* ant = l;//elemento anterior
    Lista* p = l;// para encontrar o elemento a ser retirado

    while(p != NULL && p->info != info) { //localiza o elemento
        ant = p;
        p = p->prox;
    }
    if(p != NULL) { //elemento encontrado
        if(p == l)//remo��o na cabe�a
            l = l->prox;//atualizaa cabe�a
        else//remo��o do meio
            ant->prox = p->prox;
        free(p);//libera o n� do elemento removido
    } else
        printf("Elemento n�o encontrado");
    return l;//retorna a lista

}

//Imprime os elementos da lista
//Entrada : lista
//Retorn: nenhum
//Pr�-condi��o: nenhuma
//P�s-Condi��o: os elementos sao impressos no console
void imprimir(Lista* l) {
    Lista* aux ;//= (Lista*) malloc(sizeof(Lista));
    int i = 1;
    aux = l;
    while(aux != NULL) {
        printf("elemento%d: %d\n",i,aux->info);
        aux = aux->prox;
        i++;
    }
}

//Inverte um lista
//Entrada: Lista
//Retorno: lista invertida
//Pr�-Condi��o: nenhuma
//P�s-condi��o: lista original n�o � modificada
Lista* inverter(Lista* l) {
    Lista  *invertida = NULL;
    //invertida = copiar(l);
    while(l != NULL) {
        invertida = inserir(invertida,l->info);
        l = l->prox;
    }
    return invertida;
}

//Copia uma lista e retonar ela
//entrada: lista a ser copiada
//Pr�-condi�ao: nenhuma
//P�s-Condi��es: lista copiada ponteiro
Lista* copiar(Lista* copia) {
    Lista* aux = NULL;
    while(copia != NULL) {
        aux = inserir(aux,copia->info);
        copia = copia->prox;
    }
    aux = inverter(aux);
    return aux;
}

Lista* FindUltimo(Lista* l) {
    if(l == NULL)
        return l;
    while(l->prox != NULL)
        l= l->prox;
    return l;
}
//concatena duas listas
//entrada: listas a serem concatenadas
//retorno: lista resultante da concaten��o
//Pr�-condi��o: nenhuma
//P�s-condi��es: listas originais nao sao modificadas
Lista* concatenar(Lista* l1, Lista* l2) {
    Lista* aux = NULL;
    Lista* aux2 = NULL;
    aux = copiar(l1);
    aux2 = FindUltimo(aux);
    aux2->prox = copiar(l2);
    return aux;

}
//Intercala duas listas
//Enntrada: Listas a serem intercaladas
//Retorno: lita resultante da intercala��o
//Pr�-condi��o: nenhuma
//P�s-condi��o: listas originais permancem inalteradas
Lista* intercalar(Lista* l1, Lista* l2) {
    Lista* aux = NULL;
    while(l1 != NULL) {
        aux = inserir(aux,l1->info);
        if(l2 != NULL)
            aux = inserir(aux,l2->info);
        l1 = l1->prox;
        l2 = l2->prox;
    }
    while(l2 != NULL) {
        aux = inserir(aux,l2->info);
        l2 = l2->prox;
    }
    return aux;
}
//pre- requisito: nenhum
//P�s-requisitov: l1 � modificada
Lista* append(Lista* l1, Lista* l2) {
    Lista* aux = FindUltimo(l1);
    aux->prox =  l2;

    return l1;
}

int conta_ocorrencias(Lista* l,int x) {
    int soma = 0;
    while(l != NULL) {
        if(l->info == x)
            soma++;
        l = l->prox;
    }
    return soma;
}

Lista* elimina_repetidos(Lista* l) {
    Lista* aux_percorrer = l;

    while(aux_percorrer != NULL) {
        while(conta_ocorrencias(l,aux_percorrer->info) > 1 )
            l = remover(l,aux_percorrer->info);
        aux_percorrer = aux_percorrer->prox;
    }
    return l;
}

Lista* pares(Lista* l) {
    Lista* aux = NULL;
    while(l != NULL) {
        if(l->info % 2 == 0)
            aux = inserir(aux,l->info);
        l = l->prox;
    }
    return aux;
}



int elementosLista(Lista* l) {
    int soma = 0;
    if(l == NULL)
        return 0;
    while(l != NULL) {
        soma++;
        l = l->prox;
    }
    return soma;
}

Lista* ordenar(Lista* l) {
    if(l != NULL) {
        if(l->prox != NULL) {
            if(l->info > l->prox->info) {
                Lista* aux = l;
                l = l->prox;
                aux->prox = l->prox;
                l->prox = aux;
                l->prox = ordenar(l->prox);
            }
        }
    }
    return l;
}

Lista* busca(Lista* l, TipoItem info) {
    while(l != NULL) {
        if(l->info == info) {
            return l;
        }
        l = l->prox;
    }
    return NULL;
}



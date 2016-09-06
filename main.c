#include <stdio.h>
#include <stdlib.h>

typedef struct cliente Cliente;
typedef struct node Node;

struct cliente{
    int mat;
    char nome[40];
};
struct node {
    Cliente cliente;
    Node* proximo;
};
Node* listCreate(){
    return NULL;
}

Node* listInsert(Node *list, Cliente cliente){
    Node* novo = malloc(sizeof(Node));
    novo->cliente = cliente;
    novo->proximo = list;
}

void copyString(char *s1,char *s2){
    int i = 0;
    for(i=0;*(s1+i)!='\0';i++){
        *(s2+i) = *(s1+i);
    }
    *(s2+i) = '\0';
}

Node* insertBegin(Node* first, Cliente client){
    Node* novo = malloc(sizeof(Node));
    novo->cliente = client;
    novo->proximo = first;
    return novo;
}

void insertEnd(Node* first, Cliente client){
    Node* last;
    for(last = first;last->proximo != NULL; last = last->proximo);
    Node* novo = malloc(sizeof(Node));
    last->proximo = novo;
    novo->cliente = client;
    novo->proximo = NULL;
}

int isEmpty(Node* lst){
    return (lst == NULL);
}

void printList(Node* first){
    Node* iter;
    for(iter = first; iter!= NULL; iter = iter->proximo){
        printf("-------------------------------------\n");
        printf("Matricula: %d\n",(iter->cliente).mat);
        printf("Nome: %s\n",(iter->cliente).nome);
        printf("Endereco: %p\n",iter);
    }
}
Node* findNode(Node* first, int search){
    Node* iter;
    for(iter = first; iter !=NULL; iter = iter->proximo){
        if((iter->cliente).mat == search)
            return iter;
    }
    return NULL;
}

Node* removeNode(Node* first, int search){
    Node* previous = NULL;
    Node* iter = first;

    while(iter != NULL && (iter->cliente).mat != search){
        previous = iter;
        iter = iter->proximo;
    }
    if(iter == NULL){
        return first;
    }
    if(previous == NULL){
        first = iter->proximo;
    }else{
        previous->proximo = iter->proximo;
    }
    free(iter);
    return first;
}
Node* listClear(Node* first){
    while(first != NULL){
        Node* temp = first->proximo;
        free(first);
        first = temp;
    }
    return first;
}
Node* insertAsc(Node* first, Cliente client){
    Node* novo;
    Node* previous = NULL;
    Node* iter = first;

    while(iter != NULL && (iter->cliente).mat < client.mat){
        previous = iter;
        iter = iter->proximo;
    }
    novo = malloc(sizeof(Node));
    novo->cliente = client;

    if(previous == NULL){
        novo->proximo = first;
        first = novo;
    }else{
        novo->proximo = previous->proximo;
        previous->proximo = novo;
    }
    return first;
}
Node* insertDesc(Node* first, Cliente client){
    Node* novo;
    Node* previous = NULL;
    Node* iter = first;

    while(iter != NULL && (iter->cliente).mat <= client.mat){
        previous = iter;
        iter = iter->proximo;
    }
    novo = malloc(sizeof(Node));
    novo->cliente = client;

    if(previous == NULL){
        first->proximo = novo;
        novo->proximo = NULL;
    }else{
        novo->proximo = iter;
        previous->proximo = novo;
    }
    return first;
}

int main(){
    Cliente w;
    w.mat = 123;
    copyString("Name", w.nome);

    Cliente y;
    y.mat = 456;
    copyString("Hahaha", y.nome);

    Cliente z;
    z.mat = 455;
    copyString("Lalala", z.nome);

    Node* list = listCreate();

    list = insertBegin(list, y);
    printList(list);

    printf("\n\n----- Insert Ascending ----");
    list = insertAsc(list, w);
    printList(list);

    printf("\n\n----- Insert Descending ----");
    list = insertDesc(list, z);
    printList(list);
}

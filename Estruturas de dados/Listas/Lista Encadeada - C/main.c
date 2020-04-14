#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct dataNode {
    int id;

}DataNode;

typedef struct node {
    DataNode data;
    struct node* next;
}Node;

typedef struct list {
    int size;
    Node* head;
} List;

List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list, int index);

List* createList(){

    List* list = (List*) malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;

    return list;
}

void push(List* list, DataNode data){
    Node* node = (Node*) malloc (sizeof(Node));
    
    node -> data = data;
    node -> next = list->head;
    list -> head = node;
    list -> size++;

}

void printList(List* list){

    if(isEmpty(list)){
        printf("Empty List\n");
        return;
    }

     Node* pointer = list -> head;

    while(pointer != NULL){
        printf("%d ", pointer->data.id);
        pointer = pointer->next;
    }
    printf("\n");
}

void pop(List* list){
    
    if(isEmpty(list)){
        printf("Lista vazia");
        return;
    }

    Node* pointer = list->head;
    list->head = pointer->next;
    list->size--;
    free(pointer);
}

bool isEmpty(List* list){
    return (list->size == 0); 
}

Node* atPos(List* list, int index){
    
    if(index<0 || index > list->size){
        printf("Index inválido");
        return NULL;
    }

    Node* node = list->head;
    int i;
    for (i=0;i<index;i++){
        node = node->next;
    }
    return node;
}

int main(){
    List* lista = createList();
    
    DataNode data;
    data.id  = 5;
    push(lista, data);
    data.id  = 10;
    push(lista, data);
    data.id  = 2;
    push(lista, data);
    printList(lista);

    
    return 0;
}
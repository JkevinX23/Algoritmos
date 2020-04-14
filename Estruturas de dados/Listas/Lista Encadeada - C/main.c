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
int indexOf(List* list, Node* node);
void erase(List* list, int index);
void insert(List* list, int index, DataNode data);
void exchangeNodes(List* list, Node* nodeA, Node* nodeB);
Node* minNode(List* list, int index);
Node* maxNode(List* list, int index);
void incSort(List* list);

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
    printf("Size -> %d\n", list->size);
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
    
    if(index < 0 || index >= list->size){
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

int indexOf(List* list, Node* node){
    
    int i=0;
    Node* aux = list->head;
    while(aux!=NULL){
        if(aux == node){
            return i;
        }
        aux = aux->next;
        i++;
    }
    printf("Node not index of list");
    return -1;
}

void erase(List* list, int index){
    if(list->size == 0 ){
        printf("The list not have nodes");
        return;
    }
    if(index == 0){
        Node* aux = list->head;
        list->head = list->head->next;
        list->size--;
        free(aux);
        printList(list);
        return;
    }

    Node* pointer = atPos(list,index-1);
    if(pointer->next!= NULL){
        Node* node = pointer->next;
        pointer->next = node->next;
        list->size--;
        free(node);
        printList(list);  
        return;
    }
    printf("Index invalid");
    return;
}

void insert(List* list, int index, DataNode data){
    
    if(index<0 || index>list->size){
        printf("Invalid index");
        return;
    }

    if(index == 0){
        push(list, data);
        return;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;

    Node* aux = atPos(list, index-1);
    node->next = aux->next;
    aux -> next = node;
    list->size++;
    printList(list);
}

void exchangeNodes(List* list, Node* nodeA, Node* nodeB){
    
    if(nodeA == nodeB){
        return;
    }

    int indexA = indexOf(list, nodeA);
    int indexB = indexOf(list, nodeB);
    
    if( indexA > indexB ){
        nodeA = nodeB;
        nodeB = atPos(list, indexA);

        indexA = indexB;
        indexB = indexOf(list, nodeB); 
    }

    Node* previewB = atPos(list, indexB-1);
    
    if(nodeA == list->head){
        list->head = nodeB;
    }
    else{
        Node* previewA = atPos(list, indexA-1);
        previewA -> next = nodeB;
    }
    previewB -> next = nodeA;

    Node* pointer = nodeA->next;

    nodeA->next = nodeB->next;

    nodeB->next = pointer;

    printList(list);
}

Node* minNode(List* list, int index){
    if(index < 0 || index >= list->size){
        printf("Invalid index");
        return NULL;
    }
    
    Node* min = atPos(list, index);
    Node* pointer = min;

    while(pointer != NULL){
        if( pointer->data.id < min->data.id ){
            min = pointer;
        }
        pointer = pointer->next;
    }
    return min;
}

Node* maxNode(List* list, int index){

    if(index < 0 || index >= list->size){
        printf("Invalid index");
        return NULL;
    }
    
    Node* max = atPos(list, index);
    Node* pointer = max;

    while(pointer != NULL){
        if( pointer->data.id > max->data.id ){
            max = pointer;
        }
        pointer = pointer->next;
    }
    return max;

}

void incSort(List* list){

    int i;

    for(i=0;i<list->size-1;i++){
        exchangeNodes(list, atPos(list,i), minNode(list,i));
    }
}

int main(){
    List* lista = createList();
    DataNode data;
    data.id  = 5;
    push(lista, data);
    data.id  = 10;
    push(lista, data);
    data.id  = 8;
    push(lista, data);
    data.id  = 17;
    push(lista, data);
    printList(lista);
    data.id = 1;
    insert(lista, 4 ,data);

    incSort(lista);


    return 0;
}
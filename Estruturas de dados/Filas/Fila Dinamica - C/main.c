#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
  int id;
}DataNode;

typedef struct node{
  DataNode data;
  struct node* next;
}Node;

typedef struct fila {
    Node* start;
    Node* end;
}Fila;

Fila* createQueue();
DataNode dequeue(Fila* fila);
void enqueue(Fila* fila, DataNode data);
void empty(Fila* fila);
int size(Fila* fila);
bool isEmpty(Fila* fila);


Fila* createQueue(){
  Fila* fila = (Fila*)malloc(sizeof(Fila));
  fila->end = NULL;
  fila->start= NULL;
  return fila;
}

void enqueue(Fila* fila, DataNode data){

  Node* node = (Node*) malloc (sizeof(Node));
  node->data = data;
  node->next = NULL;

  if(fila->start == NULL){
    fila->end = node;
    fila->start = node;
    return;
  }

  fila->end->next = node;
  fila->end = node;
}

bool isEmpty(Fila* fila){
    return (fila->start == NULL);
}
void printQueue(Fila* fila){

  if(isEmpty(fila)) {
     printf("Empty queue\n");
     return;
  }

  Node* pointer = fila->start;
  while(pointer != NULL){
   printf("%d ", pointer->data.id);
   pointer = pointer->next;
  }
  printf("\n");
}

int size(Fila* fila){
  
  Node* pointer = (Node*)malloc(sizeof(Node));
  int size = 1;
  pointer = fila->start;
  if(pointer==NULL)
    return 0;
  
  while(pointer!=fila->end){
    size++;
    pointer = pointer->next;
  }

  return size;
}

DataNode dequeue(Fila* fila){
  DataNode data;
  data.id = -1;
  if(size(fila) == 0){
    printf("Empty queue\n");
    return data;
  }

  Node* pointer = fila->start;
  fila->start = pointer->next;
  data = pointer->data;
  free(pointer);
  return data;

}

void empty(Fila* fila){
  while (size(fila)!=0)
  {
    dequeue(fila);
  }
  free(fila->end);
  free(fila->start);
  free(fila);
}

int main(){
  Fila* fila = createQueue();
  DataNode data;
  data.id = 10;
  enqueue(fila, data);
  data.id = 15;
  enqueue(fila, data);
  printQueue(fila);
  printf("Size:: %d\n", size(fila));
  empty(fila);
  return 0;
}



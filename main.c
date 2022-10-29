#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueList.h"


// --------------- FONCTIONS AUXILIAIRES TESTS
bool egalesList(struct List* l1, struct List* l2){

    if((l1==NULL) && (l2==NULL)){
        return true;
    }
    if((l1!=NULL) && (l2!=NULL) && (l1->size == l2->size)){
        struct Cell* c1 = l1->head;
        struct Cell* c2 = l2->head;
        while(c1 != NULL && c2 != NULL){
            if(c1->value == c2->value){
                c1 = c1->next;
                c2 = c2->next;
            }else{
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
bool egales(struct Queue* l1, struct Queue* l2){

    if((l1==NULL) && (l2==NULL)){
        return true;
    }
    return egalesList(l1->liste, l2->liste);
}

struct Queue* QueueTab(int T[], int size){
    struct Queue* l = createEmptyQueue();
    struct Cell* ptr = createCell(T[size-1]);
    l->liste->head = ptr;
    l->liste->size = size;
    for(int i=1;i < size;i++){
        ptr->next = createCell(T[size-1-i]);
        ptr = ptr->next;
    }
    return l;
}



// ----------------- TESTS ------------------------
void tests(){

    bool valid;
    int n;

    //    void enqueue(struct Queue* q, int item, bool* valid);
    printf("-------enqueue-------\n");
    struct Queue* L1 = createEmptyQueue();
    struct Queue* L2 = NULL;
    int Tab1[1] = {2};
    L2 = QueueTab(Tab1,1);
    enqueue(L1,2, &valid);

    if(egales(L1,L2) && valid == true){
        printf("test enqueue liste vide ok :D\n");
    }
    else{
        printf("test enqueue liste vide not ok :(\n");
    }

    struct Queue* L3 = createEmptyQueue();
    struct Queue* L4 = NULL;
    int Tab2[5] = {9,7,5,3,1};
    L4 = QueueTab(Tab2,5);
    enqueue(L3,9, &valid);
    enqueue(L3,7, &valid);
    enqueue(L3,5, &valid);
    enqueue(L3,3, &valid);
    enqueue(L3,1, &valid);
    if(egales(L3,L4)){
        printf("test enqueue liste non vide ok :D\n");
    }
    else{
        printf("test enqueue liste non vide not ok :(\n");
    }
    deleteQueue(L1);
    deleteQueue(L2);
    deleteQueue(L3);
    deleteQueue(L4);
    //--------------------------------------

    // int head(struct Queue* q, bool* valid);
    printf("-------head-------\n");
    struct Queue* L5 = createEmptyQueue();
    head(L5, &valid);
    if(!valid){
        printf("test head liste vide ok :D\n");
    }
    else{
        printf("test head liste vide not ok :(\n");
    }
    enqueue(L5,4, &valid);
    int result = head(L5, &valid);
    if(result == 4 && valid){
        printf("test head liste un element ok :D\n");
    }
    else{
        printf("test head liste un element not ok :(\n");
    }
    enqueue(L5,5, &valid);
    enqueue(L5,3, &valid);
    enqueue(L5,32, &valid);
    enqueue(L5,15, &valid);
    result = head(L5, &valid);
    if(result == 4 && valid){
        printf("test head liste plusieurs elements ok :D\n");
    }
    else{
        printf("test head liste plusieurs elements not ok :(\n");
    }
    deleteQueue(L5);
    //--------------------------------------

    //    int dequeue(struct Queue* q, bool* valid);
    printf("-------dequeue-------\n");
    struct Queue* l8 = createEmptyQueue();
    dequeue(l8, &valid);
    if(valid == false) {
        printf("test dequeue liste vide ok :D\n");
    }
    else{
        printf("test dequeue liste vide not ok :(\n");
    }
    deleteQueue(l8);
    int T8[5] = {2,10,50,99,114};
    struct Queue* l81 = QueueTab(T8,5);
    result = dequeue(l81, &valid);
    if(valid==true) {
        if(result==2 && dequeue(l81, &valid) == 10){
            printf("test dequeue liste non vide ok :D\n");
        }
        else{
            printf("test dequeue liste non vide not ok :(\n");
        }
    }
    else{
        printf("test dequeue liste non vide not ok :(\n");
    }

    deleteQueue(l81);
//    //--------------------------------------
//
//    //    int queueSize(struct Queue* q);
    printf("-------queueSize-------\n");
    struct Queue* L11 = createEmptyQueue();
    if(queueSize(L11) == 0){
        printf("test queueSize liste vide ok :D\n");
    }
    else{
        printf("test queueSize liste vide not ok :(\n");
    }
    enqueue(L11,9, &valid);
    if(queueSize(L11) == 1){
        printf("test queueSize liste un element ok :D\n");
    }
    else{
        printf("test queueSize liste un element not ok :(\n");
    }

    enqueue(L11,9, &valid);
    enqueue(L11,7, &valid);
    enqueue(L11,5, &valid);
    enqueue(L11,3, &valid);
    enqueue(L11,1, &valid);
    enqueue(L11,0, &valid);
    if(queueSize(L11) == 7){
        printf("test queueSize liste plusieurs elements ok :D\n");
    }
    else{
        printf("test queueSize liste plusieurs elements not ok :(\n");
    }
    deleteQueue(L11);
//    //--------------------------------------
//
//    //    void printQueue(struct Queue* q);
    printf("-------printQueue-------\n");
    struct Queue* l60 = createEmptyQueue();
    printf("test printQueue liste vide\n *Si votre sorti est: rear -> NULL <- front\n *dans la prochaine ligne alors c'est bon :D\n");
    printQueue(l60);
    deleteQueue(l60);
    int T6[5] = {2,10,50,99,114};
    struct Queue* l6 = QueueTab(T6,5);
    printf("test printList liste non vide\n *Si votre sorti est: \nrear ->  114 - 99 - 50 - 10 - 2  <- front\n *dans la prochaine ligne alors c'est bon :D\n");
    printQueue(l6);
    deleteQueue(l6);
    //--------------------------------------

    //    bool isQueueEmpty(struct Queue* q);
    printf("-------isQueueEmpty-------\n");
    struct Queue* l7 = createEmptyQueue();
    if(isQueueEmpty(l7)) {
        printf("test isQueueEmpty liste vide ok :D\n");
    }
    else{
        printf("test isQueueEmpty liste vide not ok :(\n");
    }
    deleteQueue(l7);
    int T7[5] = {2,10,50,99,114};
    struct Queue* l71 = QueueTab(T7,5);
    if(!isQueueEmpty(l71)) {
        printf("test isQueueEmpty liste non vide ok :D\n");
    }
    else{
        printf("test isQueueEmpty liste non vide not ok :(\n");
    }
    deleteQueue(l71);
//    //--------------------------------------
//
//    //    deleteQueue(struct Queue* q);
    printf("-------deleteQueue-------\n");
    printf("executer: valgrind --tool=memcheck <nom_programme> :D\n");
    printf("TOUTES les listes utilises dans ces tests seront effacées avec cette fonction!\n");
    //--------------------------------------

}


int main(){

    tests();

    return 0;
}



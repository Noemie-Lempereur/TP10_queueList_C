#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueList.h"

struct Queue* createEmptyQueue(){
    struct Queue* queue =malloc(sizeof(struct Queue));
    if (queue!=NULL){
        queue->liste=createEmptyList();
    }
    return queue;
}

void enqueue(struct Queue* q, int item, bool* valid){
    if(q!=NULL) {
        bool b;
        bool* val=&b;
        addFirst(q->liste,item);
        *valid=true;
        return;
    }
    *valid=false;
}

int head(struct Queue* q, bool* valid){
    if((q!=NULL)&&(isQueueEmpty(q)==false)){
        int a;
        bool b;
        bool* vali=&b;
        a=getItemPos(q->liste,q->liste->size-1,vali);
        if(*vali==true){
            *valid=true;
            return a;
        }
    }
    *valid=false;
    return -1;
}

int dequeue(struct Queue* q, bool* valid){
    if((q!=NULL)&&(isQueueEmpty(q)==false)){
        *valid=true;
        int a;
        bool b;
        bool* vali=&b;
        a=head(q,vali);
        if(*vali==true) {
            bool c;
            bool* val=&c;
            deleteItemPos(q->liste,q->liste->size-1,val);
            if(*val==true) {
                *valid = true;
                return a;
            }
        }
    }
    *valid=false;
    return -1;
}

int queueSize(struct Queue* q){
    if(q!=NULL){
        return q->liste->size;
    }
    return -1;
}

bool isQueueEmpty(struct Queue* q){
    if((q!=NULL)&&(queueSize(q)==0)){
        return true;
    }
    return false;
}

void printQueue(struct Queue* q){
    if(q != NULL){
        bool valid = true;
        for(int i = 0; i < queueSize(q); i++){
            if(i == 0){
                printf("rear -> ");
            }
            printf("%d ", getItemPos(q->liste, i, &valid));
            if(i == queueSize(q)-1){
                printf("<- front\n");
            }
            else{
                printf("- ");
            }
        }
        if(isQueueEmpty(q)){
            printf("rear -> NULL <- front\n");
        }
    }
}

void deleteQueue(struct Queue* q){
    if(q!=NULL) {
        deleteList(q->liste);
        free(q);
    }
}

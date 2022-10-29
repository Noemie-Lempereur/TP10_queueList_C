#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


#ifndef TP10_3_QUEUELIST_H
#define TP10_3_QUEUELIST_H

struct Queue{
    struct List* liste;
};

struct Queue* createEmptyQueue();

void enqueue(struct Queue* q, int item, bool* valid);

int head(struct Queue* q, bool* valid);

int dequeue(struct Queue* q, bool* valid);

int queueSize(struct Queue* q);

bool isQueueEmpty(struct Queue* q);

void printQueue(struct Queue* q);

void deleteQueue(struct Queue* q);

#endif //TP10_3_QUEUELIST_H

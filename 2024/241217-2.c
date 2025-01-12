#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct QNode {
    element data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} QList;

QList *createQList() {
    QList *q;
    q = (QList *)malloc(sizeof(QList));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(QList *q) {
    if (q->front == NULL) return 1;
    else return 0;
}

void enQueue(QList *q, element item) {
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->next = NULL;  

    if (q->front == NULL) { 
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode; 
        q->rear = newNode; 
    }
}

element deQueue(QList *q) {
    QNode *removed = q->front;
    element item;

    if (isEmpty(q)) return 0;
    else {
        item = removed->data;
        q->front = removed->next;
        if (q->front == NULL) q->rear = NULL;
        free(removed);
        return item;
    }
}

element peek(QList *q) {
    if (!isEmpty(q)) return q->front->data;
    return 0;
}

void printList(QList *q) {
    QNode *p = q->front;
    printf("\n[");
    while (p != NULL) { 
        printf(" %c", p->data);
        p = p->next;
    }
    printf(" ]");
}

int main(void) {
    QList *q = createQList();
    element data;

    enQueue(q, 'A');
    printList(q);

    enQueue(q, 'B');
    printList(q);

    deQueue(q);
    printList(q);

    enQueue(q, 'C');
    printList(q);

    data = peek(q);
    printf("\n peek item : %c", data);

    deQueue(q);
    printList(q);

    deQueue(q);
    printList(q);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct circular_queue
{
    int front;
    int rear;
    int *data;5
    int size;
};
typedef struct circular_queue cq;

void makeEmpty(cq *c, int max)
{
    c->size = max;
    c->front = c->size - 1;
    c->rear = c->size - 1;
    c->data = (int *)malloc(max * sizeof(int));
}

bool isFull(cq *c)
{

    return ((c->front == (c->rear + 1) % c->size));
}

bool isEmpty(cq *c)
{

    return (c->rear == c->front);
}

void enqueue(cq *c, int newItem)
{
    if (isFull(c))
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        c->rear = (c->rear + 1) % c->size;
        c->data[c->rear] = newItem;
    }
    printf("%d is enques\n", newItem);
}

int dequeue(cq *c)
{
    if (isEmpty(c))
    {
        printf("Stack Underflow\n");
    }
    c->front = (c->front + 1) % c->size;
    return c->data[c->front];
}

void display(cq *c)
{
    if (isEmpty(c))
    {
        printf("Stack Underflow");
        exit(1);
    }
    else
    {
        int i;
        for (i = ((c->front + 1) % c->size); i != c->rear; i = ((i + 1) % c->size))
        {
            printf("%d\n", c->data[i]);
        }
        printf("%d\n", c->data[c->rear]);
    }
}

int main()
{

    cq q;
    cq *q1 = &q;
    int choice;
    int num, size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    makeEmpty(q1, size);

    while (1)
    {
        printf("Enter a choice : \n 1.Enqueue 2.Dequeue 3.display 4.exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to insert\n");
            scanf("%d", &num);
            enqueue(q1, num);
            break;
        case 2:
            printf("%d is removed\n", dequeue(q1));
            break;
        case 3:
            display(q1);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}
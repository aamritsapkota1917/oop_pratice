
   
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodetype
{
    struct Nodetype *next;
    int info;
};
typedef struct Nodetype Node;

Node *head = NULL;
int size = 0;

void isEmpty()
{
    if (!head)
    {

        printf("Empty Linked List");
        exit(1);
    }
}
void insert_at_begining(int new_data)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        Node *temp = head;
        head = newnode;
        newnode->next = temp;
    }
    newnode->info = new_data;
}

void insert_at_last_position(int new_data)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    newnode->next = NULL;
    newnode->info = new_data;
}

void insert_at_specific_position(int new_data, int index)
{

    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *new_temp = NULL;

    if (head)
    {
        Node *temp = head;
        if (index == 0)
        {

            insert_at_begining(new_data);
            return;
        }
        else
        {

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
        }
        new_temp = temp->next;
        temp->next = newnode;
    }
    else
    {
        head = newnode;
    }
    newnode->next = new_temp;
    newnode->info = new_data;
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void remove_at_last()
{
    isEmpty();

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void remove_at_begining()
{
    isEmpty();

    head = head->next;
}

void remove_at_specified_position(int index)
{
    isEmpty();
    if (index == 0)
    {

        remove_at_begining();
    }
    else
    {

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }
}

int main()
{

    int choice, new_number, index;

    while (1)
    {
        printf("Enter the choice: \n1.Insert at the begining \n2.Insert the end \n3.Insert at the specific position \n4.Dispay \n5.Delete at the begining \n6.Delete at the end \n7. Delete at any specific position  \n8.Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the number to insert: \n");
            scanf("%d", &new_number);
            insert_at_begining(new_number);
            break;
        }
        case 2:
        {
            printf("Enter the number to insert: \n");
            scanf("%d", &new_number);
            insert_at_last_position(new_number);
            break;
        }
        case 3:
        {
            printf("Enter the number to insert: \n");
            scanf("%d", &new_number);
            printf("Enter the position to insert: \n");
            scanf("%d", &index);
            insert_at_specific_position(new_number, index);
            break;
        }
        case 4:
        {
            display();
            break;
        }

        case 5:
        {
            remove_at_begining();
            break;
        }

        case 6:
        {
            remove_at_last();
            break;
        }
        case 7:
        {
            printf("Enter the position to delete: \n");
            scanf("%d", &index);
            remove_at_specified_position(index);
            break;
        }
        case 8:
        {
            exit(0);
        }

        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}
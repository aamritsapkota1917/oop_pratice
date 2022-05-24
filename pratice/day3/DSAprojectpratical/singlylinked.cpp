#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
typedef struct node nd;
nd *head = NULL;
nd *getNewNode()
{
    nd *newNode = new nd;
    return newNode;
}
int totalNode()
{
    int count = 0;
    if (head == NULL)
        return count;
    else
    {
        nd *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
void insert_atfirst(int data)
{
    nd *newNode = getNewNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void insert_atEnd(int data)
{
    nd *newNode = getNewNode();
    newNode->data = data;
    nd *temp = head;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        newNode->next = NULL;
        temp->next = newNode;
    }
}
void insert_atany(int data)
{
    nd *newNode = getNewNode();
    newNode->data = data;
    int pos;
    cout << "Enter the position you want to insert" << endl;
    cin >> pos;
    if (pos > totalNode() + 1)
    {
        cout << "invalid insertion" << endl;
        return;
    }
    nd *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void delete_atfirst()
{
    if (head == NULL)
        cout << "List is empty!" << endl;
    else
    {
        nd *temp = head;
        cout << "The deleted item is " << head->data << endl;
        head = head->next;
        delete temp;
    }
}
void delete_atend()
{
    if (head == NULL)
        cout << "List is empty!" << endl;
    else if (head->next == NULL)
    {
        cout << "The deleted item is " << head->data << endl;
        delete head;
        head = NULL;
    }
    else
    {
        nd *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        cout << "The deleted item is " << temp->next->data << endl;
        delete temp->next;
        temp->next = NULL;
    }
}
void delete_atany()
{
    int pos;
    cout << "Enter the position you want to delete" << endl;
    cin >> pos;
    if (pos > totalNode())
    {
        cout << "invalid deletion" << endl;
        return;
    }
    nd *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    nd *hold;
    hold = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted item is :" << hold->data << endl;
    delete hold;
}
void display()
{
    if (head == NULL)
        cout << "The list is empty" << endl;
    else
    {
        nd *temp = head;
        cout << "The list seems to be:" << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    int data;
    do
    {
        cout << "***Menu***" << endl;
        cout << "1.Insert at beginning \n2.Insert at end \n3.Insert at specific position \n4.Delete from beginning \n5.Delete from end \n6.Delete from specific position \n7.Display\n8.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number to be inserted" << endl;
            cin >> data;
            insert_atfirst(data);
            break;
        case 2:
            cout << "Enter the number to be inserted" << endl;
            cin >> data;
            insert_atEnd(data);
            break;
        case 3:
            cout << "Enter the number to be inserted" << endl;
            cin >> data;
            insert_atany(data);
            break;
        case 4:
            delete_atfirst();
            break;
        case 5:
            delete_atend();
            break;
        case 6:
            delete_atany();
            break;
        case 7:
            display();
            break;
        default:
            cout << "Invalid choice!!!" << endl;
        }
    } while (choice < 10);
}
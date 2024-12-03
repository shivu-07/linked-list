#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("memory allocation failed...!");
        return NULL;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

struct Node *Atbeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (newNode != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node *AtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (newNode != NULL)
    {
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

struct Node *AtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (newNode != NULL)
    {
        if (position == 1)
        {
            head = Atbeginning(head, data);
        }
        int i = 1;
        struct Node *temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node *DeleteAtBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty..!");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *DeleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is already empty.\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
    }
}

struct Node *DeleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("list is empty..!");
        return NULL;
    }
    struct Node *temp = head;
    if (position == 0)
    {
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position not found.\n");
        return head;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

struct Node *DeleteByValue(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("list is empty..!");
        return NULL;
    }
    struct Node *temp = head;
    if (head->data == value)
    {
        head = head->next;
        free(temp);
        return head;
    }
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Value not found.\n");
        return head;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

void display(struct Node *head)
{
    printf("\nLinked list is:\n");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int data;
    int insertion, deletion;
    int option;

    // data insertion
    do
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        printf("\nChoose where to insert the node:\n");
        printf("1.insert at Beginning\n");
        printf("2.insert at End\n");
        printf("3.insert at Position\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            head = Atbeginning(head, data);
            break;
        case 2:
            head = AtEnd(head, data);
            break;
        case 3:
            printf("\nEnter position to insert: ");
            int in_position;
            scanf("%d", &in_position);
            head = AtPosition(head, data, in_position);
            break;
        default:
            printf("Invalid Insertion choice. Please enter again.\n");
            break;
        }
        printf("do you want to insert? if yes(1),No(0): ");
        scanf("%d", &insertion);
    } while (insertion);
    display(head);

    printf("Do you want to delete Data? if yes(1),No(0): ");
    int yes;
    scanf("%d", &yes);
    
    if (yes)
    {
        // data deletion
        do
        {
            printf("\nChoose where to delete the node:\n");
            printf("1.delete at Beginning\n");
            printf("2.delete at End\n");
            printf("3.delete at Position\n");
            printf("4.delete by value\n");
            printf("Enter your option: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                head = DeleteAtBegin(head);
                break;
            case 2:
                head = DeleteAtEnd(head);
                break;
            case 3:
                printf("\nEnter position to delete: ");
                int del_position;
                scanf("%d", &del_position);
                head = DeleteAtPosition(head, del_position);
                break;
            case 4:

                printf("\nEnter value to delete: ");
                int value;
                scanf("%d", &value);
                head = DeleteByValue(head, value);
                break;
            default:
                printf("Invalid Deletion choice. Please enter again.\n");
                break;
            }
            printf("do you want to delete? if yes(1),No(0): ");
            scanf("%d", &deletion);
        } while (deletion);
        display(head);
    }
    return 0;
}
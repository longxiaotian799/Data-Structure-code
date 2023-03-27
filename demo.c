#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int main()
{
    node *head = NULL;
    int data;
    head->next = NULL;
    head = (node*)malloc(sizeof(node));
    head->data = 1;
    printf("%d", head->data);
}
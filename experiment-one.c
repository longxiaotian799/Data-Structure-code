#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of a list
#define MAXSIZE 100

// Define the type of an element in the list 
typedef int Elemtype;

// Define a struct for a Sqlist, which contains an array of elements and its length
typedef struct 
{
    Elemtype elem[MAXSIZE]; // The array to hold the elements
    int length; // The number of elements in the array
} Sqlist;

/* Initializes a Sqlist by setting its length to 0 */
void InitList(Sqlist *L) 
{
    L->length = 0;
}

/* Inserts a new element x into the Sqlist at position i */
int insert(Sqlist *L, int i, Elemtype x) 
{
    if(L->length == MAXSIZE - 1) 
    {
        printf("the list is overflow!\n");
        return 0;
    }
    if(i < 1 || i > L->length + 1) 
    {
        printf("position is not correct!\n");
        return 0;
    }
    for(int j = L->length; j >= i; j--) 
    {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i-1] = x;
    L->length++;
    return 1;
}

/* Locates the position of the first occurrence of element e in the Sqlist */
int Locate(Sqlist L, Elemtype e) 
{
    for(int i = 0; i < L.length; i++) 
    {
        if(L.elem[i] == e) 
        {
            return i;
        }
    }
    return -1;
}

/* Deletes the element at position i in the Sqlist */
void delete (Sqlist *L, int i) 
{
    if(i < 1 || i > L->length) 
    {
        printf("delete fail\n");
        return;
    }
    for(int j = i; j < L->length; j++) 
    {
        L->elem[j-1] = L->elem[j];
    }
    L->length--;
}

/* Prints the elements of the Sqlist */
void listprint(Sqlist L) 
{
    for(int i = 0; i < L.length; i++) 
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


/* The main function */
int main() 
{
    Sqlist A, B;
    InitList(&A);
    InitList(&B);

    insert(&A, 1, 3);
    printf("After inserting 3 into A: ");
    listprint(A);
    insert(&A, 2, 5);
    printf("After inserting 5 into A: ");
    listprint(A);
    insert(&A, 3, 8);
    printf("After inserting 8 into A: ");
    listprint(A);
    insert(&A, 4, 9);
    printf("After inserting 9 into A: ");
    listprint(A);

    insert(&B, 1, 2);
    printf("After inserting 2 into B: ");
    listprint(B);
    insert(&B, 2, 4);
    printf("After inserting 4 into B: ");
    listprint(B);
    insert(&B, 3, 6);
    printf("After inserting 6 into B: ");
    listprint(B);
    insert(&B, 4, 8);
    printf("After inserting 8 into B: ");
    listprint(B);

    printf("set A: ");
    listprint(A);
    printf("set B: ");
    listprint(B);

    for(int i = 0; i < A.length; i++) 
    {
        int index = Locate(B, A.elem[i]);
        if(index != -1) 
        {
            delete(&A, i+1);
            i--;
            printf("After deleting an element from A: ");
            listprint(A);
        }
    }

    printf("set A-B: ");
    listprint(A);

    return 0;
}
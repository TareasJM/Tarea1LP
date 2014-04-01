#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "Color.h"

typedef struct Node
{
    Color color;
    // previous node
    struct Node* prev;
    // next node
    struct Node* next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    Node *current;
    int size;
    int pos;
} Lista;

void initLista(Lista *lista)
{
    lista->head = lista->tail = NULL;
    lista->size = 0;
    lista->pos = 0;
}

void next(Lista *lista)
{
    if(lista->current->next != NULL)
    {
        lista->current = lista->current->next;
        lista->pos++;
    }
}

void prev(Lista *lista)
{
    if(lista->current != lista->head)
    {
        lista->current = lista->current->prev;
        lista->pos--;
    }
}

void goToStart(Lista *lista)
{
    lista->current = lista->head;
    lista->pos = 1;
}

void goToEnd(Lista *lista)
{
    lista->current = lista->tail;
    lista->pos = lista->size;
}

void clear(Lista *lista)
{
    goToEnd(lista);
    while(lista->size > 0)
    {
        prev(lista);
        free(lista->current->next);
    }
    free(lista->current);
}

void append(Lista *lista, Color newColor)
{
    Node newNodo = (Node*)malloc(sizeof(Node));
    newNodo->color = newColor;
    newNodo->next = NULL;
    newNodo->prev = Lista->tail;
    lista->tail->next = newNodo;
    lista->tail = newNodo;
    lista->size++;
}

void remove(Lista *lista, char *colorName)
{
    goToStart(lista);
    while(lista->size >= lista->pos)
    {
        if (strcmp(lista->current->color->nombre, colorName) == 0)
        {
            oldNode = lista->current;
            lista->current->prev->next = lista->current->next;
            lista->current->next->prev = lista->current->prev;
            lista->current = list->current->prev;
            lista->pos--;
            lista->size--;
            free(olNode);
            return ;

        }

        next(lista);
    }
}

void listToText(Lista *lista)
{
    FILE *archivo;
    
    archivo = fopen("colors.txt","w");
    while(lista->size >= lista->pos)
    {   
        Color *color = lista->current->color
        fprintf(archivo, "%s\n%d\n%d\n%d\n",color->nombre, color->red, color->green, color->blue);
        next(lista);
    }


}

void textToList(Lista *lista)
{
    FILE *archivo;

    archivo = fopen("colors.txt","r");

    int red,green,blue;
    char *nombre = (char*)malloc(sizeof(char));

    while(fscanf(archivo,"%s\n%d\n%d\n%d\n", nombre,&red,&green,&blue) == 4)
    {
        Color *color = (Color*)malloc(sizeof(Color));
        color->name = nombre;
        color->red = red;
        color->green = green;
        color->blue = blue;
        append(lista,color);
    }
}

Color getCurrentColor(Lista *lista)
{
    return lista->current->color;
}
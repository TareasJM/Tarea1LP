#include "Lista.h"
#include "Color.h"

Lista* initLista()
{    
    Lista *lista;
    lista = (Lista *)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    lista->pos = 0;
    return lista;
}

int getPos(Lista *lista)
{
    return lista->pos;
}

int getSize(Lista *lista)
{
    return lista->size;
}

int next(Lista *lista)
{
    if(lista->current->next != NULL)
    {
        lista->current = lista->current->next;
        lista->pos++;
        return 0;
    }
    return 1;
}

int prev(Lista *lista)
{
    if(lista->current != lista->head)
    {
        lista->current = lista->current->prev;
        lista->pos--;
        return 0;
    }
    return 1;
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
    while(prev(lista) == 0)
    {
        free(lista->current->next);
    }
    free(lista->head);
}

void append(Lista *lista, Color *newColor)
{
    Node *newNodo = (Node*)malloc(sizeof(Node));
    newNodo->color = newColor;
    if (lista->size == 0)
    {
        lista->head = newNodo;
        lista->tail = newNodo;
        lista->current = newNodo;
        lista->pos = 1;
    }
    else
    {
        newNodo->next = NULL;
        newNodo->prev = lista->tail;
        lista->tail->next = newNodo;
        lista->tail = newNodo;
    }
    lista->size++;
}

int removeNode(Lista *lista, char *colorName)
{
    goToStart(lista);
    do
    {
        printf("strcmp %s - %s \n", lista->current->color->nombre, colorName);
        if (strcmp(lista->current->color->nombre, colorName) == 0)
        {
            Node *oldNode;
            oldNode = lista->current;
            lista->current->prev->next = lista->current->next;
            lista->current->next->prev = lista->current->prev;
            lista->current = lista->current->prev;
            lista->pos--;
            lista->size--;
            free(oldNode);
            return 0;

        }
    }while(next(lista) == 0);
    return 1;
}

void listToText(Lista *lista)
{
    FILE *archivo;
    archivo = fopen("colors.txt","w");
    goToStart(lista);
    int n = lista->size;
    int i = 0;
    do
    {   
        i++;
        Color *color = lista->current->color;
        fprintf(archivo, "%s\n%d\n%d\n%d\n",color->nombre, color->red, color->green, color->blue);
    }
    while (next(lista) == 0);

    fclose(archivo);

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
        color->nombre = nombre;
        color->red = red;
        color->green = green;
        color->blue = blue;
        append(lista,color);
        nombre = (char*)malloc(sizeof(char));
    }
    fclose(archivo);
}

Color* getCurrentColor(Lista *lista)
{
    return lista->current->color;
}
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Element
{
    int data;
    Element* p_next;
};

struct List
{
    Element* p_head;
    Element* p_tail;
    size_t size;
};

List*
list_init(void)
{
    List* p_list = malloc(sizeof(List));
    if(p_list == NULL)
        return NULL;

    p_list -> p_head = NULL;
    p_list -> p_tail = NULL;
    p_list -> size = 0;

    return p_list;
}

void
list_cons_front(List* p_list, int data)
{
    Element* p_elem = malloc(sizeof(Element));
    if(p_elem == NULL)
        exit(EXIT_FAILURE);

    p_elem -> data = data;
    p_elem -> p_next = p_list -> p_head;

    p_list -> p_head = p_elem;
    if(p_list -> size == 0)
        p_list -> p_tail = p_elem;
    p_list -> size++;
}

void
list_cons_back(List* p_list, int data)
{
    Element* p_elem = malloc(sizeof(Element));
    if(p_elem == NULL)
        exit(EXIT_FAILURE);

    p_elem -> data = data;
    p_elem -> p_next = NULL;

    p_list -> p_tail -> p_next = p_elem;
    p_list -> p_tail = p_elem;
    p_list -> size++;
}

void
list_pop_front(List* p_list)
{
    if(p_list -> size == 0)
        return;
    else if(p_list -> size == 1)
    {
        free(p_list -> p_head);
        p_list -> p_head = NULL;
        p_list -> p_tail = NULL;
        p_list -> size--;
        return;
    }

    Element* p_elem = p_list -> p_head;
    p_list -> p_head = p_elem -> p_next;
    p_list -> size--;
    free(p_elem);
}

void
list_pop_back(List* p_list)
{
    if(p_list -> size == 0)
        return;
    else if(p_list -> size == 1)
    {
        free(p_list -> p_head);
        p_list -> p_head = NULL;
        p_list -> p_tail = NULL;
        p_list -> size--;
        return;
    }

    int i;
    Element* p_elem = p_list -> p_head;
    for(i = 1; i < p_list -> size - 1; i++)
        p_elem = p_elem -> p_next;

    p_list -> p_tail = p_elem;
    p_list -> size--;
    free(p_elem -> p_next);
    p_elem -> p_next = NULL;
}

size_t
list_size(List* p_list)
{
    return p_list -> size;
}

void
list_print(List* p_list)
{
    Element* p_elem = p_list-> p_head;
    while(p_elem != NULL)
    {
        printf("%d -> ", p_elem -> data);
        p_elem = p_elem -> p_next;
    }
    printf("NULL\n");
}

void
list_free(List* p_list)
{
    Element* p_elem = p_list -> p_head;
    while(p_elem != NULL)
    {
        Element *p_elemToFree = p_elem;
        p_elem = p_elem -> p_next;
        free(p_elemToFree);
    }
    free(p_list);
}

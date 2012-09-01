#ifndef LIST_H_
#define LIST_H_

typedef struct Element Element;
typedef struct List List;

List* list_init(void);

void list_free(List* p_list);

void list_cons_front(List* p_list, int data);
void list_cons_back(List* p_list, int data);

void list_pop_front(List* p_list);
void list_pop_back(List* p_list);

size_t list_size(List* p_list);

void list_print(List* p_list);

#endif

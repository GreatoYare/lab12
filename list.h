#ifndef LAB_11_LIST_H
#define LAB_11_LIST_H

#include "item.h"

typedef struct {
    WoWMounts *head;
    int size;
} List;

/* Init Array */
List *makeList();

/* Create new node */
void add(WoWMounts *mount, List *list);

/* Create new node to prelast */
void addToPreLast(WoWMounts *mount, List *list);

/* Get node by id */
WoWMounts *get(int id, List *list);

/* Delete note by id */
int DeletePrevious(int id, List *list);

/* Write all list */
void display(List *list, int q, int Max);

/* Destroy List */
void destroy(List *list, int q, int Max);

#endif //LAB_11_LIST_H

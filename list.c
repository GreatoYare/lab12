#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "item.h"

List *makeList() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(WoWMounts *mount, List *list) {
    WoWMounts *current = NULL;
    mount->next = NULL;
    mount->id = 0;

    if (list->head == NULL) {
        list->head = mount;
        mount->next = (struct WoWMounts *) list->head;
    } else {
        mount->next = (struct WoWMounts *) list->head;
        mount->id++;
        current = list->head;
        while (current->next != (struct WoWMounts *) list->head) {
            mount->id++;
            current = (WoWMounts *) current->next;
        }
                current->next = (struct WoWMounts *) mount;
    }
}

WoWMounts *get(int id, List *list) {
    WoWMounts *current = list->head;
    int c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->id == id) {
            return current;
        }
        current = (WoWMounts *) current->next;
    }
    return NULL;
}

int Delete(int id, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->id == id) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }

        return k;
}

int DeleteByCost(int cost, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->cost == cost) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByName(char *name, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->name, name) == 0) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByQuest(char *quest, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->quest, quest) == 0){
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByAchieve(char *achieve, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->achieve, achieve) == 0) {
            previous->next = current->next;
            if (strcmp(current->achieve, achieve) == 0)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}


int DeleteByCharacter(char *character, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->character, character) == 0) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}


int DeleteByChance(double chance, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->chance == chance) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByAddon(char *addon, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->addon, addon) == 0) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByLocation(char *location, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (strcmp(current->location, location) == 0) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByHolders(double holders, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->holders == holders) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

int DeleteByRate(int rate, List *list) {
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int k = 0, c = 0;
    while (current != list->head || c == 0) {
        c++;
        if (current->rate == rate) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (WoWMounts *) current->next;
            free(current);
             k++;
            }
        previous = current;
        current = (WoWMounts *) current->next;
    }
        return k;
}

void display(List *list, int q, int Max) {
    WoWMounts *current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    int c = 0;
    while ((current != list->head || c == 0) && c != Max-q) {
            c++;
        printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
               current->id,current->cost, current->name, current->quest, current->achieve, current->character, current->chance, current->addon, current->location, current->holders, current->rate);
        current = (WoWMounts *) current->next;
    }
}

void destroy(List *list, int q, int Max) {
    WoWMounts *current = list->head;
    WoWMounts *next = current;
    int c = 0;
    while ((current != list->head || c == 0) && c!=Max-q) {
        c++;
        next = (WoWMounts *) current->next;
        free(current);
        current = next;
    }
    free(list);
}

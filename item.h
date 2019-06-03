#ifndef LAB_12_ITEM_H
#define LAB_12_ITEM_H

typedef struct {
    int id;                     //id
    int cost;                   //cost of mount
    char *name;                 //name of mount
    char *quest;                //quest to earn mount
    char *achieve;              //achievement to earn mount
    char *character;            //from who dropped
    double chance;              //chance of drop
    char *addon;                //addition of Wow
    char *location;             //Where drops
    double holders;             //How much people have
    int rate;                   //Subjective rate
    struct WoWMounts *next;     // Link to next
} WoWMounts;

#endif //LAB_12_ITEM_H

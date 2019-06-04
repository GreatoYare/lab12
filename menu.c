#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "file_manager.h"
#include "checks.h"

// For adaptive clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

WoWMounts *readItem(WoWMounts *wowMounts)
{
    wowMounts->cost = enterInt("Write cost of mount: ");
    wowMounts->name = enterString("Write name of mount: ");
    wowMounts->quest = enterString("Write quest where you can earn mount: ");
    wowMounts->achieve = enterString("Write achievement where you can earn mount: ");
    wowMounts->character = enterString("Write from what character you can earn mount: ");
    wowMounts->chance = enterDouble("Write chance of mount drop: ");
    wowMounts->addon = enterString("Write addition where mount stand: ");
    wowMounts->location = enterString("Write location where mount stand: ");
    wowMounts->holders = enterDouble("Write percent of mount holders: ");
    wowMounts->rate = enterInt("Write your rate of mount: ");
    return wowMounts;
}

void showAbout()
{
    system(CLEAR);
    puts("================= [About] ===================");
    puts("Title: \"Labwork 12\"");
    puts("Author: Spiridonov Leonid 8307");
    puts("=============================================");
    printf("Press anything to continue: ");
    getch();
}

int showDelete(List *list, int q)
{
    int id = 0;
    int qcheck = q;
    system(CLEAR);
    puts("================ [Delete] ===================");
    puts("0. ID");
    puts("1. Cost");
    puts("2. Name");
    puts("3. Quest");
    puts("4. Achievement");
    puts("5. Character");
    puts("6. Chance");
    puts("7. Addition");
    puts("8. Location");
    puts("9. Holders");
    puts("10. Subjective rate");
    puts("=============================================");
    id = enterInt("Write your field: ");

    if (id == 0)
    {
        id = enterInt("Write id of mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=Delete(id, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 1)
    {
        int cost = enterInt("Write cost of mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByCost(cost, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 2)
    {
        char *name = enterString("Write name of mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByName(name, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 3)
    {
        char *quest = enterString("Write quest for earn mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByQuest(quest, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 4)
    {
        char *achieve = enterString("Write achievement for earn mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByAchieve(achieve, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 5)
    {
        char *character = enterString("Write character from who earned item: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByCharacter(character, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 6)
    {
        double chance = enterDouble("Write drop chance of mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByChance(chance, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 7)
    {
        int addon = enterString("Write addition with this mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByAddon(addon, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 8)
    {
        char *location = enterString("Write location where you can found this mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByLocation(location, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 9)
    {
        double holders = enterDouble("Write percent of mount holders: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByHolders(holders, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    else if (id == 10)
    {
        int rate = enterInt("Write your subjective rate of mount: ");
        puts("");
        printf("%d notes have been deleted\n", q+=DeleteByRate(rate, list));
        if (qcheck == q) printf("There is no notes for delete");
    }
    printf("Write anything to continue: ");
    getch();
    return q;
}

void showAdd(List *list)
{
    WoWMounts *wowMounts = malloc(sizeof(WoWMounts));

    system(CLEAR);
    puts("================== [Add] ====================");
    puts("At this point you can add a new mount\nto the library. Follow the instructions.");
    puts("=============================================");

    readItem(wowMounts);

    add(wowMounts, list);
    puts("Mount was added to library");
    printf("Write anything to continue: ");
    getch();
}

void showList(List *list, int q, int Max)
{
    system(CLEAR);
    puts("================= [List] ====================");
    display(list, q, Max);
    puts("=============================================");
    printf("Write anything to continue: ");
    getch();
}

int showMenu(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int c = 0, z;
    int q = 0, Max = 0;
    z = Max+1;
    int menu = 0;
    if (z == 1)
    {
        while (current != list->head || c == 0)
        {
            c++;
            Max++;
            current = (WoWMounts *) current->next;
        }
    }
    while (menu != 4)
    {
        int mq = q;
        system(CLEAR);
        puts("================= [MENU] ===================");
        puts("0. Abouts");
        puts("1. Add new note");
        puts("2. Print list");
        puts("3. Delete element");
        puts("4. Exit");
        puts("============================================");
        menu = enterInt("Write your command: ");

        if (menu == 0)
        {
            showAbout();
        }
        else if (menu == 1)
        {
            showAdd(list);
            Max++;
        }
        else if (menu == 2)
        {
            showList(list, q, Max);
        }
        else if (menu == 3)
        {
            q = showDelete(list, mq);
        }
    }
  return q;
}

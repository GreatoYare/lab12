#include <stdio.h>
#include "item.h"
#include "list.h"
#include "file_manager.h"
#include "menu.h"

#define FILENAME "WOWMOUNTS.csv"

int main() {
    // Read data from file
    FILE *readFile = fopen(FILENAME, "r");
    List *list = makeList();
    readListFromFile(readFile, list);
    fclose(readFile);

    WoWMounts *current = list->head;
    int c = 0, z = 1;
    int q = 0, Max = 0;
    z = Max+1;
    if (z == 1)
    {
        while (current != list->head || c == 0)
        {
            c++;
            Max++;
            current = (WoWMounts *) current->next;
        }
    }

    q = showMenu(list);

    // Save data to file
    FILE *writeFile = fopen(FILENAME, "w");
    saveListToFile(writeFile, list, q, Max);
    destroy(list, q, Max);
    fclose(writeFile);
    return 0;
}

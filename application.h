#ifndef APPLICATION_H
#define APPLICATION_H

int fileToTable(FILE *fp, hashTable ht, linked_list *ll);
int listToFile(linked_list *ll);
void filter_alnum(char *s, char *punct);

#endif //APPLICATION_H
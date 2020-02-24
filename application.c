#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashTable.h"
#include "linked_list.h"
#include "application.h"
#define WORDLEN 50  //The length of a word

int fileToTable(FILE *fp, hashTable ht, linked_list *ll)
{
    printf("\nReading...\n");

    char *word = malloc(sizeof(char) * WORDLEN);
    char *punct = malloc(sizeof(char) * 5);

    while(fscanf(fp, "%s", word) != EOF){
        add_to_list(ll, word);
        filter_alnum(word, punct);
        add_to_hashTable(word, ht);
        add_to_hashTable(punct, ht);
        memset(word, 0, sizeof(word));  //empty the string for the next reading
    }

    free(word);
    free(punct);
    return 1;
}

int listToFile(linked_list *ll)
{
    FILE *fp = fopen("reproduced.txt", "w");
    linked_list *tmp = ll;

    while(tmp->next != NULL){
		tmp = tmp->next;
		fputs(tmp->data, fp);
        fputc(' ', fp);
	}
    printf("The input file reproduced successfully, please check file 'reproduced.txt'\n");
    
    fclose(fp);
    return 1;
}

void filter_alnum(char *s, char *punct){
    for (char *p = s; *p; ++p)
        if(isalnum(*p))
            *s++ = *p;
        else if(ispunct(*p))
            *punct++ = *p;
    *s = '\0';
    *punct = '\0';
}

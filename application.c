#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashTable.h"
#include "linked_list.h"
#include "application.h"
#define TABLESIZE 3500  //The amount of commond English words is about 3000 and the amount of punctuation is 14, others save for numbers
#define WORDLEN 50  //The length of a word

int fileToTable(FILE *fp, hashTable ht, linked_list *ll)
{
    printf("Reading...\n");

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

int main(int argc, char *argv[])
{
    /* The expected input from command line will be ./app text.txt */
    if(argc == 2){
        FILE *fp = fopen(argv[1], "r");
        
        if(fp == NULL){
            printf("File does not exist\n");
            return -1;
        }
        else{
            printf("File opened successfully\n");
            hashTable ht = init_hashTable(TABLESIZE);
            linked_list *head = (linked_list* )malloc(sizeof(linked_list));

            if(fileToTable(fp, ht, head)){
                fclose(fp);
                printf("Reading done, start to print the table now:\n");
                int total = print_hashTable(ht);
                printf("\nThe amount of stored text items in table is %d\n", total);
                listToFile(head);
            }
            else{
                printf("Error occurs during reading");
                return -1;
            }
        }
    }
    else{
        printf("Invalid input format\n");
        return -1;
    }

    return 0;
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

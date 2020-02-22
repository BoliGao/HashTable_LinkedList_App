#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#include "application.h"
#define TABLESIZE 3000  //The amount of commond English words is about 3000
#define WORDLEN 50  //The length of a word

int fileToTable(FILE *fp, hashTable ht)
{
    printf("Reading...\n");

    char word[WORDLEN];

    while(fscanf(fp, "%s", word) != EOF){
        add_to_hashTable(word, ht);
        memset(word, 0, sizeof(word));  //empty the string for the next reading
    }

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
            if(fileToTable(fp, ht)){
                printf("Reading done, start to print now:\n");
                print_hashTable(ht);
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
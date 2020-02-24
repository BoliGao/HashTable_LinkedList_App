#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#include "linked_list.h"
#include "application.h"
#define TABLESIZE 3500  //The amount of commond English words is about 3000 and the amount of punctuation is 14, others save for numbers

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
            printf("\nFile opened successfully\n");
            hashTable ht = init_hashTable(TABLESIZE);
            linked_list *head = (linked_list* )malloc(sizeof(linked_list));

            if(fileToTable(fp, ht, head)){
                fclose(fp);
                printf("\nReading done, start to print the table now:\n");
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
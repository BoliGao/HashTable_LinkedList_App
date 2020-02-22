#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "hashTable.h"

/* create index for a string *key, rerurn the index value */
int hash(char *key, int tableSize)
{
	unsigned int hashVal = 0;
	
	if(*key == '\0' || tableSize < MINISIZE)
		return -1;
	
	while(*key != '\0')
		hashVal = (hashVal << 5) + *key++;
	
	return hashVal % tableSize;
}

/* initialize hash_table with a specified size */ 
hashTable init_hashTable(int tableSize)
{
	hashTable hT;
	
	if(tableSize < MINISIZE){
		printf("Table size is too small\n");
		return NULL;
	}
	
	/* Allocate table */
	hT = (struct hashTb *)malloc(sizeof(struct hashTb));
	if(hT == NULL){
		printf("Out of space\n");
		return NULL;
	}
	
	hT->tableSize = NextPrime(tableSize);		//It is better to set a table size with a prime number
	
	/* Allocate array of lists */
	hT->tableLists = malloc(sizeof(struct listNode) * hT->tableSize);
	if(hT->tableLists == NULL){
		printf("Out of space\n");
		return NULL;
	}
	
	/* Allocate list headers */
	for(int i=0; i < hT->tableSize; i++){
		hT->tableLists[i] = malloc(sizeof(struct listNode));
		if(hT->tableLists[i] == NULL){
			printf("Out of space\n");
			return NULL;
		}
		else
			hT->tableLists[i]->next = NULL;
	}
	
	return hT;
}

/* find if the key is already in the table */
position find_in_hashTable(char *key, hashTable hT)
{
	if(key == NULL || hT == NULL)
		return NULL;
	
	position p;
	list l;
	
	l = hT->tableLists[ hash(key, hT->tableSize) ];
	p = l->next;

	while( p != NULL && (strcasecmp(p->data, key) != 0))	//case insensitive string comparasion
		p = p->next;
	
	return p;
}

/* Insert a key to the table */
int add_to_hashTable(char *key, hashTable hT)
{
	position pos, newNode;
	list l;
	int count = 0;

	if(*key == '\0' || hT == NULL)
		return -1;

	pos = find_in_hashTable(key, hT);	//check if the key is already in the table
	if(pos == NULL){		//key is not found
		newNode = (struct listNode*)malloc(sizeof(struct listNode));
		if(newNode == NULL){
			printf("Out of space\n");
			return -1;
		}
		else{
			l = hT->tableLists[hash(key, hT->tableSize)];
			while(l->next != NULL){
				l = l->next;	//go to the last node of the linked list
				count++;
			}

			l->next = newNode;
			newNode->data = (char *)malloc(sizeof(char) * 20);
			strcpy(newNode->data, key);
			newNode->next = NULL;

			return count;
		}
	}
	else{
		//printf("key is already in the list\n");
		return -1;
	}
}

/* print all elements in the table */
void print_hashTable(hashTable hT)
{
	list l;
	position p;
	
	if(hT == NULL)
		printf("Error: Hash table is NULL\n");
	else{
		for(int i=0; i < hT->tableSize; i++){
			l = hT->tableLists[i];
			p = l->next;
			if(p != NULL)
				printf("Index%d:", i);
			while(p){
				printf(" %s->\n", p->data);
				p = p->next;
			}
			//printf("");
		}
	}
}

/* Two functions for finding the next prime number */
bool IsPrime(int number)
{

    if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {

        if (number % (divisor - 1) == 0)
            return false; 

        if (number % (divisor + 1) == 0)
            return false;

        divisor += 6;

    }

    return true;
}

int NextPrime(int a)
{
    while (!IsPrime(a))
		a++;
	
    return a;
}









		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
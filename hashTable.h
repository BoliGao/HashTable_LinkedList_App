#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#define MINISIZE 1

struct listNode;
typedef struct listNode *position;
struct hashTb;
typedef struct hashTb *hashTable;

struct listNode
{
	char *data;
	position next;
	int occurrence;
};

typedef position list;

/* List *tableLists will be an array of lists, allocated later */
struct hashTb
{
	int tableSize;
	list *tableLists;
};

int hash(char *key, int tableSize);
hashTable init_hashTable(int tableSize);
void print_hashTable(hashTable hT);
int add_to_hashTable(char *key, hashTable hT);
position find_in_hashTable(char *key, hashTable hT);
bool IsPrime(int num);
int NextPrime(int a);

#endif //HASHTABLE_H
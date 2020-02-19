#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function will create a new list item and add that to end of list */
int add_to_list(linked_list *ll, char *s)
{
	int index;
	linked_list *tmp = ll;
	
	if(ll == NULL)	//check if pointer is NULL
		return -1;
	else if(s == NULL)	//check if pointer is NULL
		return -1;
	else{		
		while(tmp->next != NULL)	//find the end of the list
			tmp = tmp->next;
		
		/* create a new node */
		tmp->next = (linked_list* )malloc(sizeof(linked_list));
		tmp->next->data = s;
		tmp->next->index = tmp->index + 1;
		tmp->next->next = NULL;
		index = tmp->next->index;	
	
		return index;
	}
}

/* Function will displays the required element (pointed by parameter linked_list *ll) in a list */
/* Return: -1 element not found , 0 ok */
int display_item(linked_list *ll)
{
	if(ll == NULL)	//check if pointer is NULL
		return -1;
	else if(ll->next == NULL){	//check if the list is empty
		return -1;
		printf("element not found");
	}
	else{	//normal condition
		printf("Index: %d\tData: %s\tNext: %p\n", ll->next->index, ll->next->data, ll->next->next);
		return 0;
	}	
}

/* List all elements in a list */
/* return: number of elements in list */
int display_list(linked_list *ll)
{
	linked_list *tmp = ll;
	
	if(ll == NULL)	//check if pointer is NULL
		return -1;
	else if(ll->next == NULL){		//empty list
		printf("Only a head\n");
		return 1;
	}
	else{	//normal condition
		printf("The whole list:\n");
		while(tmp->next != NULL){
			tmp = tmp->next;
			printf("Index: %d\tData: %s\tNext: %p\n", tmp->index, tmp->data, tmp->next);
		}
		return (tmp->index)+1;
	}
}

/* Search for a data *s from a list */
/* Return: NULL if not found, pointer to */
linked_list * search_from_list(linked_list *ll, char *s)
{
	linked_list *tmp = ll;
    while( tmp != NULL && strcmp(tmp->data,s) != 0) 
        tmp = tmp->next;
    return tmp;  
}

/* Delete item from a list and free space */
/* Return value: -1 on error, length of remaining list */
int delete_from_list(linked_list *ll, int index)
{
	if(ll == NULL)	//check if pointer is NULL
		return -1;
	else if(index < 0)	//check if index is valid	
		return -1;
	else{	//normal condition
		linked_list *current = ll;
		linked_list *previous = NULL;
		
		//locate the element we want to delete
		while (current->index != index && current->next != NULL){
			previous = current;			
			current = current->next;
		}

		if(current->index == index){	//when the location found
			if (current == ll){		//if the element is the head
				ll = current->next;
			}
			else{
				previous->next = current->next;
				while(previous->next){		//rearrange the sequence of the index
					previous->next->index = previous->index + 1;
					previous = previous->next;
				}
			}
 
			free (current);	//free the memory
			current = NULL;
			return previous->index;
		}
		else{	//when the location not found
			return -1;
			printf("index not found");
		}
	}
}

/* remove all items from the list and will free allocated memory */
/* return value items deleted from the list */
int empty_list(linked_list *ll)
{
	int count = 0;
	linked_list *current = NULL,*tmp = NULL;
	
	if(ll==NULL)	//check if pointer is NULL
		return -1;
	else{
		current = ll->next;
		while(current){		
			tmp = current->next;
			free(current);
			current = tmp;
			count++;
		}
		
		ll->next = NULL;
		return count;
	}
}

/* swap order of two items */
/* return value
	0 in OK
	-1 if either items was not in the list (content of the list did not change)
*/
int swap_items(linked_list *f, linked_list *s)
{
	int check = 0;
	
	if(f == NULL || s == NULL)	//check if pointer is NULL
		return -1;
	else{
		linked_list *tmp1 = f->next;
		linked_list *tmp2 = s->next;
		
		//check if either items was not in the list
		while(tmp1 && check == 0){	//f before s
			if(tmp1 == s)
				check = 1;
			tmp1 = tmp1->next;
		}
		while(tmp2 && check == 0){	//f behind s
			if(tmp2 == f)
				check = 1;
			tmp2 = tmp2->next;
		}
		
		if(check == 0)	//when either items was not in the list
			return -1;
		else{	//normal condition
			linked_list *tmp = (linked_list* )malloc(sizeof(linked_list));
			tmp->data = f->data;
			tmp->next = f->next;
			f->data = s->data;
			f->next = s->next;
			s->data = tmp->data;
			s->next = tmp->next;
			free(tmp);
			return 0;
		}
	}
}

/* Sort list in rising order based on the data */
int sort_list(linked_list *ll)
{
	if(ll==NULL)	//check if pointer is NULL
		return -1;
	else{	//bubble sort method
		linked_list *current = NULL;
		linked_list *tail = NULL;
		current = ll;
 
		while(current != tail){
			while(current->next != tail){
				if(strcmp(current->data, current->next->data)){
					char *tmp = current->data ;
					current->data = current->next->data ;
					current->next->data = tmp;
					}
				current = current->next ;
				}
			tail = current;
			current = ll;
		}
		
		return 0;
	}
}

/* will count the number of elements in the list */
/* return value: amount */
int linkedlist_status(linked_list *ll)
{
	int count = 0; 
	
	if(ll==NULL)	//check if pointer is NULL
		return -1;
	else{
		linked_list *tmp = ll;
		while (tmp){ 
			count++; 
			tmp = tmp->next; 
		} 
		return count; 
	} 
}

















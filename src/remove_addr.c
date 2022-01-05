#include <stddef.h>
#include <stdlib.h>
#include "../include/address_book.h"


void remove_contact_pos(struct address_chain *tmp_chain, int position) 
{

	struct address_block *tmp = tmp_chain->front;
	struct address_block *prev = NULL;

	
	for(int i = 1; i < position; i++) {
		prev = tmp;
		if(tmp->pNext != NULL) {tmp = tmp->pNext;}
	}	

	
	//if first element
	if(tmp_chain->front == tmp) {
		tmp_chain->front = tmp->pNext;
		free(tmp);
	}//if last
	else if(tmp_chain->rear == tmp) {
		prev->pNext = NULL;
		tmp_chain->rear = prev;
		free(tmp);
	}
	else{ 
		prev->pNext = tmp->pNext;
		free(tmp);
	}

}


void free_list(struct address_chain *chain) { //add to remove_addr?
	struct address_block *tmp = chain->front;
	struct address_block *prev;
	
	do {	
		//if only 1 address present || last
		if(tmp == chain->rear){
			free(tmp);
			tmp = NULL;
		}
		else {
			prev = tmp;
			tmp = tmp->pNext;
			free(prev);
		}
		
	}while(tmp != NULL);
	
	chain->front = NULL;
	chain->rear = NULL;
		
	
}

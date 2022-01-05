#include "../include/address_book.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//for debug
#include <stdio.h>

void init_chain(struct address_chain *tmp_chain) {
	tmp_chain->front = tmp_chain->rear = NULL;
	load_contacts(tmp_chain);
}

void init_block(struct address_block *tmp_block) {
	tmp_block->pNext = NULL;
}


void add_contact(struct address_chain *tmp_chain, struct address_block *tmp) {

	struct address_block *tmp_block = malloc(sizeof(struct address_block));
	memcpy(tmp_block, tmp, sizeof(struct address_block));

	//if no addresses are present
	if(tmp_chain->front == NULL) {
		tmp_chain->front = tmp_block;
		tmp_chain->rear = tmp_block;
	}
	else{
		tmp_chain->rear->pNext = tmp_block;
		tmp_chain->rear = tmp_block;

	}
		

}



void add_contact_pos(struct address_chain *tmp_chain, struct address_block *tmp_block, int position) {

	struct address_block *tmp = tmp_chain->front;
	struct address_block *prev = NULL;
	struct address_block *block = malloc(sizeof(struct address_block));
	memcpy(block, tmp_block, sizeof(struct address_block));
	
	for(int i = 1; i < position; i++) {
		prev = tmp;
		if(tmp->pNext != NULL) {tmp = tmp->pNext;}
	}	

	
	//if first element
	if(tmp_chain->front == tmp && position == 1) {
		block->pNext = tmp;
		tmp_chain->front = block;
	}//if last
	else if(tmp_chain->rear == tmp && prev == tmp) {
		tmp->pNext = block;
		tmp_chain->rear = block;
	}
	else{ 
		prev->pNext = block;
		block->pNext = tmp;
	}
	



}












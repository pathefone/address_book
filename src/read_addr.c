#include "../include/address_book.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void print_address_book(struct address_chain *chain) 
{
	struct address_block *tmp = chain->front;
	printf("Listing contacts:\n");

	if(tmp != NULL) {
		
		int i = 0;

		do {
			if(i != 0) {
				if(tmp->pNext != NULL) {tmp = tmp->pNext;}
			}
			printf("\n******************\n");
			printf("First name: %s\n", tmp->name);
			printf("Last name: %s\n", tmp->last_name);
			printf("Phone num: %s\n", tmp->phone_num);
			printf("Email: %s\n", tmp->email);
			printf("******************\n");
			i++;	

		}while(tmp->pNext != NULL);

	}
	else {
		printf("No addresses present\n");
	}


}

void print_contact(struct address_block *tmp)
{

	printf("\n The address has been found");
	printf("\n******************\n");
	printf("First name: %s\n", tmp->name);
	printf("Last name: %s\n", tmp->last_name);
	printf("Phone num: %s\n", tmp->phone_num);
	printf("Email: %s\n", tmp->email);
	printf("******************\n");


}


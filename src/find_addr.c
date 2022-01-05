#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/address_book.h"


struct address_block *find_contact_pos(struct address_chain *tmp_chain, int position) 
{

	struct address_block *tmp = tmp_chain->front;
	
	for(int i = 1; i < position; i++) {
		if(tmp->pNext != NULL) {tmp = tmp->pNext;}
	}	
	
	return tmp;
	
}

char *to_lower_case(char *input) {

	size_t i;
	for(i=0; i<100; i++)
		input[i] = tolower(input[i]);

return input;
}

//options
//1-first name
//2-last name
//3-email
//4-number
struct address_block *find_contact_by_data(struct address_chain *tmp_chain)
{
	struct address_block *tmp = tmp_chain->front;
	
	char user_input[100];
	int option;
	
	printf("Enter option\n");
	printf("Find address by:\n");
	printf("(1) Name\n");
	printf("(2) Surname\n");
	printf("(3) Email\n");
	printf("(4) Number\n");
	printf("Your option: ");
	get_user_input(user_input);
	option = atoi(user_input);
	
	
	if(option == 1) {
		printf("Enter name: ");
	}
	else if(option == 2) {
		printf("Enter surname: ");
	}
	else if(option == 3) {
		printf("Enter email:");
	}
	else if(option == 4) {
		printf("Enter number: ");
	}
	else {
		printf("No such option");
	}
	get_user_input(user_input);
	strcpy(user_input, to_lower_case(user_input));
	
	
	
	do {
		if(option == 1) {
			if(strcmp((to_lower_case(tmp->name)), user_input) == 0) {
				
				goto exit;
			}
		}
		else if(option == 2) {
			if(strcmp((to_lower_case(tmp->last_name)), user_input) == 0) {
				goto exit;
			}
		}
		else if(option == 3) {
			if(strcmp((to_lower_case(tmp->email)), user_input) == 0) {
				goto exit;
			}
		}
		else if(option == 4) {
			if(strcmp((to_lower_case(tmp->phone_num)), user_input) == 0) {
				goto exit;
			}
		}
		
		
		if(tmp->pNext != NULL) {tmp = tmp->pNext;} //if only 1 block exists
		  
		
	
	
	}while(tmp->pNext != NULL);
	
	printf("Not found\n");
	exit(0);



exit:
return tmp;
}

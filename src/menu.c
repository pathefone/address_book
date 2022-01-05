#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/address_book.h"

void menu(struct address_chain *chain)
{
	struct address_block *block = malloc(sizeof(struct address_block));
	init_block(block);
	char user_input[100];
	char option[1];
	int int_option;

	menu:
	printf("\nTo add a new user press 1\n");
	printf("To print address book press 2\n");
	printf("To add contact in a specific position press 3\n");
	printf("To remove contact by position press 4\n");
	printf("To remove all contacts press 5\n");
	printf("To find an address by position press 6\n");
	printf("To find an address by name,surname,email or number press 7\n");
	printf("To exit press 0\n");
	printf("Your option: ");
	get_user_input(option);
	int_option = atoi(option);
	
	while(int_option != 0) {

	if(int_option == 1 || int_option == 3) {	
		printf("\nTo add new contact please enter first name:");
		get_user_input(user_input);
		strcpy(block->name, user_input);
		printf("Enter last name:");
		get_user_input(user_input);
		strcpy(block->last_name, user_input);
		printf("Enter phone number:");
		get_user_input(user_input);
		strcpy(block->phone_num, user_input);
		printf("Enter email:");
		get_user_input(user_input);
		strcpy(block->email, user_input);

		
		
		if(int_option == 3) {
			printf("\n Position to add contact: ");
			get_user_input(user_input);
			int_option = atoi(user_input);
			if(chain->front == NULL) {add_contact(chain, block); goto menu;}
			add_contact_pos(chain, block, int_option);
		}
		else{
			add_contact(chain, block);
		}
		
		goto menu;
	}
	else if(int_option == 2) {
		print_address_book(chain);
		goto menu;
	}
	else if(int_option == 4) {
		printf("\n Position to remove contact: ");
		get_user_input(user_input);
		int_option = atoi(user_input);
		if(chain->front == NULL) {printf("The list is empty"); goto menu;}
		remove_contact_pos(chain, int_option);
		goto menu;
	}
	else if(int_option == 5) {
		free_list(chain);
		goto menu;
	}
	else if(int_option == 6) {
		printf("\n Position to find contact: ");
		get_user_input(user_input);
		int_option = atoi(user_input);
		if(chain->front == NULL) {printf("The list is empty"); goto menu;}
		struct address_block *found = find_contact_pos(chain, int_option);
		print_contact(found);
		goto menu;
	}
	else if(int_option == 7) {
		struct address_block *found = find_contact_by_data(chain);
		print_contact(found);
		goto menu;
	
	}
	else {
		printf("No such option!\n");
		goto menu;
	}
	
	
}

free(block);

}

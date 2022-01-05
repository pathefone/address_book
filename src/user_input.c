#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAX_LENGTH 100

void get_user_input(char *input) {
	char tmp[MAX_LENGTH];
	
	if(fgets(tmp, MAX_LENGTH, stdin) != NULL) {
		strcpy(input, tmp);
	}
	else {
		printf("Wrong input");
	}
	
	input[strcspn(input, "\n")] = 0;
}


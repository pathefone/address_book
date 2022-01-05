#include "../include/address_book.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void load_contacts(struct address_chain *chain)
{
	struct address_block *tmp_block = malloc(sizeof(struct address_block));
	
	const char *names[10] = {"John","Simon","Darryl","Pam","Michael","Kevin","Oscar","Phyllis","Muhammad","Mike"};
	const char *surnames[10] = {"Tyson", "Ali", "Jordan", "Wallace", "Son", "Lukaku", "Mbappe", "Smith", "Washington", "Suzuki"};
	const char *phones[10] = {"+37067777777", "+3706514751681", "+37066666666", "+37067788999", "+37067788000","+37061718911","+37063788333","+37062782929","+37060788900","+37067748391",};
	const char *emails[10] = {"jimmy@yahoo.com", "robin@protonmail.ch", "staccc@gmail.com", "zafter@labas.lt", "kipt@yandex.ru","skyblue@sky.com","ak47@yandex.ru", "luminor4@gmail.com", "zizi@gmail.com", "end@lava.com"};
	
	size_t i;
	for(i=0;i<10;i++) {
		strcpy(tmp_block->name, names[i]);
		strcpy(tmp_block->last_name, surnames[i]);
		strcpy(tmp_block->phone_num, phones[i]);
		strcpy(tmp_block->email, emails[i]);
		
		add_contact(chain, tmp_block);
		
		
}

}






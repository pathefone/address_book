#include "../include/address_book.h"
#include <stdlib.h>


int main(void)
{
	struct address_chain *chain = malloc(sizeof(struct address_chain));
	init_chain(chain);
	menu(chain);
	free_list(chain);
	free(chain);

	return 0;
}

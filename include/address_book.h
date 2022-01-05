//single block in an address chain
struct address_block {
	char name[100];
	char last_name[100];
	char phone_num[100];
	char email[100];
	struct address_block *pNext;
};

//a chain(linked_list) of address blocks
struct address_chain {
	struct address_block *front;
	struct address_block *rear;
};


void add_contact(struct address_chain *tmp_chain, struct address_block *tmp_block);

void add_contact_pos(struct address_chain *tmp_chain, struct address_block *tmp_block, int position);

void init_chain(struct address_chain *tmp_chain);

void free_list(struct address_chain *chain);

void get_user_input(char *input);

void print_address_book(struct address_chain *chain);

void menu(struct address_chain *chain);

void init_block(struct address_block *tmp_block);

void remove_contact_pos(struct address_chain *tmp_chain, int position);

struct address_block *find_contact_pos(struct address_chain *tmp_chain, int position);

void print_contact(struct address_block *tmp);

struct address_block *find_contact_by_data(struct address_chain *tmp_chain);

char *to_lower_case(char *input);

void load_contacts(struct address_chain *chain);

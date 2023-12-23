#include "bank.h"

int checkentry(entry_data_t *data)
{
	int i = 0;

	entry_t entry_list[] = {
		{"create account", create_account},
		{"exit", exit_bank},
		{NULL, NULL}
	};

	data->tokens = get_tok(data->line);
	data->token = malloc(sizeof(char *) * data->tokens);
	tokenize(data);

	while (entry_list[i].entry)
	{
		if (strcmp(entry_list[i].entry, data->token[0]))
			entry_list[i].fptr(data);
		i++;
	}
	if (entry_list[i].entry == NULL)
		return (0);
	return (1);

}


void create_account(entry_data_t *data)
{
	char* line;
	int r, c;
	size_t n;

	printf("Enter Firstname\n");
	r = getline(&line, &n, stdin);
	{
		if (r == -1)
			printf("Name cannot be empty\n\n to quit enter quit");
		else
			c = strlen(line);
			line[c - 2] = '\0';
			if(strlen(line) > 50)
				printf("Firstname cannot be more that 50 characters long");
	}
	fclose(data->file);
}

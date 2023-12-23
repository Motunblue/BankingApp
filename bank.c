#include "bank.h"

/**
 * main - Does the account creation or sign in
*/
int main(void)
{
	const char* filename = "data.txt";
	char *line = NULL;
	size_t n;
	int r, entry;
	entry_data_t *data = malloc(sizeof(entry_data_t));
	
	data->file = fopen(filename, "r");

	here:
		entryprompt();

		while (1)
		{
			/*data =  { CLEAR };*/
			r = getline(&line, &n, stdin);
			if (r == -1)
			{
				printf("Invalid entry");
				goto here;
			}
			data->line = line;


			entry = checkentry(data);
			if (entry) 
			{
				printf("You have not typed an allowed entry"); /*Move this somewhere eles*/
				goto here;/*Implement some cleaning here*/
			}
		}
		
	/* Enter a command while get line is not null */
	/* Call another function to handle this */
	return (0);
}


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


void exit_bank(entry_data_t *data)
{
	(void)data;

	printf("Goodbye!");
	exit(0);
}

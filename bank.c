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

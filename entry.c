#include "bank.h"

void save(account_info *user) {
	sqlite3 *db;
	char *errMessage = 0;
	int rc = sqlite3_open("bank.db", &db);

	if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

	const char *sql = "CREATE TABLE IF NOT EXISTS PERSON("
                       "ID INT PRIMARY KEY     NOT NULL,"
                       "NAME           TEXT    NOT NULL,"
                       "AGE            INT     NOT NULL);";
	
	rc = sqlite3_exec(db, sql, 0, 0, &errMessage);
}

void entryprompt(void)
{
	printf("Welcome to The Blue bank\n\n");
	printf("You can proceed to login by first providing your email\n");
	printf("Don't have an account? please enter \"create account\"\n\n");
    printf("To exit, please enter \"quit\"\n\n");
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
		if (!strcmp(entry_list[i].entry, data->token[0]))
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

	first:
		printf("Enter Firstname\n");
		r = getline(&line, &n, stdin);
		{
			if (r == -1)
				printf("Name cannot be empty\n\n to quit enter quit");
			else
			{
				c = strlen(line);
				line[c - 2] = '\0';
				if (strlen(line) > 50) {
					printf("Firstname cannot be more that 50 characters long");
					goto first;
				}
					
				else if (strlen(line) < 2)  {
					printf("Firstname cannnot be less than 2 characters long");
					goto first;
				}
				else
					data->user->first_name = line;	
			}
				
				
		}
	/*last:	
		printf("Enter Lastname\n");
		r = getline(&line, &n, stdin);
		{
			if (r == -1)
				printf("Lastme cannot be empty\n\n to quit enter quit");
			else
			{
				c = strlen(line);
				line[c - 2] = '\0';
				if (strlen(line) > 50) {
					printf("Lastname cannot be more that 50 characters long");
					goto last;
				}
					
				else if (strlen(line) < 2)  {
					printf("lastname cannnot be less than 2 characters long");
					goto last;
				}
				else
					data->user->first_name = line;
				
			}
				
				
		}*/
		/*Write a save function to save the struct to a file*/
	save(data->user);
}

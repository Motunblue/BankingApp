#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_account(FILE *file);

int main(void)
{
	const char* filename = "data.txt";
	FILE* file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Uhm, seems you're new here :)\n\
Please create and account to continue\n\n");
		sleep(0.05);
		create_account(file);
	}
	/* Enter a command while get line is not null */
	/* Call another function to handle this */
}

void create_account(FILE *file)
{
	char *line = NULL;
	size_t n;
	int r;
	
	if (!file)
		file = fopen("data.txt", "a");
	printf("Enter Firstname and Lastname\
	        (should be seperated by a space)\n");
	r = getline(&line, &n, stdin);
	{
		if (r == -1)
			printf("Account cannot be created\n");
	}
	/* Save created account as struct */
	fclose(file);
		
}

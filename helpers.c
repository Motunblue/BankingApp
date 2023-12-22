#include "bank.h"

void entryprompt(void)
{
	printf("Welcome to the Motun bank\n");
	printf("You can proceed to login by first providing your email\n");
	printf("Don't have an account? please enter \"create account\"\n");
    printf("To exit, please enter quit\"\n");
}



/**
  * get_tok - a funtion that takes in the token
  * @str: the string the function takes
  * Return: 0
  */
unsigned int get_tok(char *str)
{
        unsigned int count = 0, in_word = 0, i;

        for (i = 0; str[i] != '\0'; i++)
        {
                if ((str[i] != ' ' && str[i] != '\n') && !in_word)
                {
                        count++;
                        in_word = 1;
                }
                else if (str[i] == ' ' || str[i] == '\n')
                        in_word = 0;
        }
        return (count);
}

/**
  * tokenize - a function that tokenizes a string
  * @linearg: the arguments
  * @token: the first string to be tokenized
  * @tokens: the strings after the first to be tokenized
  * Return: 0
  */
void tokenize(entry_data_t *data)
{
        int i = 0;

        data->token[i] = strtok(data->line, " \n");
        for (i = 1; i < data->tokens; i++)
                data->token[i] = strtok(NULL, " \n");
        data->token[i] = NULL;
}
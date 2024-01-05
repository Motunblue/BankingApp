#ifndef _BANK_H_
#define _BANK_H_


/******************** Header files *****************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlite3.h>
#include <regex.h>


/************* Macros ************/
#define CLEAR {0, NULL, NULL, NULL}

/**************** Structure ****************/
typedef struct account_info_s
{
	int id;
	char* first_name;
	char* last_name;
	char* balance;
} account_info;

typedef struct entry_data_s
{
	int tokens;
	char **token;
	char *line;
	FILE *file;
	account_info *user;
} entry_data_t;


typedef struct entry_s
{
	char *entry;
	void (*fptr)(entry_data_t *);
} entry_t;


typedef struct users_s
{
	account_info user;
	struct users_s *next;  
} users_t;



/**************** Function Protypes ****************/
void create_account(entry_data_t *);
int checkentry(entry_data_t *data);
void exit_bank(entry_data_t *data);


/**************** Helper Functions ****************/
void entryprompt(void);
unsigned int get_tok(char *str);
void tokenize(entry_data_t *data);


#endif

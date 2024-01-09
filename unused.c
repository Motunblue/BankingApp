

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

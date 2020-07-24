#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <mysql/mysql.h>
#include "sql_test.h"
#include "logger.h"


void testSQLConnection(){

	MYSQL *sql; //SQL connection
	sql = mysql_init(NULL); //Init connection
	char hostname[200];
	unsigned int port;
	char user[200];
	char *password;
	char database[200];

	printf("====== SQL TEST ======\n");
	printf("Hostname: ");
	scanf("%s", &hostname);
	printf("Port: ");
	scanf("%u", &port);
	printf("Database: ");
	scanf("%s", &database);
	printf("Username: ");
	scanf("%s", &user);
	password = getpass("Password: ");

	//Try to connect with given data
	if(mysql_real_connect(sql, hostname, user, password, database, 33000, NULL, 0) == NULL){
		fprintf (stderr, "ERROR: mysql_real_connect():"
        "%u (%s)\n",mysql_errno (sql), mysql_error (sql)); //On Error, print it
		char buffer[1024];
		snprintf(buffer, sizeof(buffer), "[ERROR] mysql_read_connect(): %u (%s)\n", mysql_errno(sql), mysql_error(sql));
		logger(buffer);
		mysql_close(sql); //Close connection
	} else {
		printf("Successfully connected to: %s", hostname);
		logger("SQL Test Successful.");
	}

	mysql_close(sql); //Close connection
}
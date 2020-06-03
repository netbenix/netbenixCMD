CC= gcc
ARGS= -export-dynamic -ansi -std=gnu99
CFLAGS= $(shell pkg-config --cflags gtk+-3.0) -I/usr/include/mysql
LDLIBS= $(shell pkg-config --libs gtk+-3.0) -L/usr/lib/mysql -lmysqlclient
OBJ= main.o logo.o logger.o help.o os_info.o gtk_test.o sql_test.o

netbenixCMD: $(OBJ)
	$(CC) $(CFLAGS) $(ARGS) -o netbenixCMD $(OBJ) $(LDLIBS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
logo.o: etc/logo.c
	$(CC) $(CFLAGS) -c etc/logo.c
logger.o: utils/logger.c
	$(CC) $(CFLAGS) -c utils/logger.c
help.o: commands/help.c
	$(CC) $(CFLAGS) -c commands/help.c
os_info.o: utils/os_info.c
	$(CC) $(CFLAGS) $(ARGS) -c utils/os_info.c
gtk_test.o: commands/gtk_test.c
	$(CC) $(CFLAGS) -c commands/gtk_test.c
sql_test.o: commands/sql_test.c
	$(CC) $(CFLAGS) -c commands/sql_test.c
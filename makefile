CC= gcc
ARGS= -export-dynamic -ansi -std=gnu99
CFLAGS= $(shell pkg-config --cflags gtk+-3.0) -I/usr/include/mysql
LDLIBS= $(shell pkg-config --libs gtk+-3.0) -L/usr/lib/mysql -lmysqlclient
OBJ= main.o logo.o logger.o help.o sys_info.o gtk_test.o sql_test.o show_dir.o change_dir.o update_check.o man.o your-reality.o

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
sys_info.o: utils/sys_info.c
	$(CC) $(CFLAGS) $(ARGS) -c utils/sys_info.c
gtk_test.o: utils/gtk_test.c
	$(CC) $(CFLAGS) -c utils/gtk_test.c
sql_test.o: utils/sql_test.c
	$(CC) $(CFLAGS) -c utils/sql_test.c
show_dir.o: commands/show_dir.c
	$(CC) $(CFLAGS) -c commands/show_dir.c
change_dir.o: commands/change_dir.c
	$(CC) $(CFLAGS) -c commands/change_dir.c
update_check.o: utils/update_check.c
	$(CC) $(CFLAGS) -c utils/update_check.c
man.o: etc/man.c
	$(CC) $(CFLAGS) -c etc/man.c
your-reality.o: etc/your-reality.c
	$(CC) $(CFLAGS) -c etc/your-reality.c
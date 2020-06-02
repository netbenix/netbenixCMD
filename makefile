CC= gcc
ARGS= -export-dynamic
CFLAGS= $(shell pkg-config --cflags gtk+-3.0)
LDLIBS= $(shell pkg-config --libs gtk+-3.0) 
OBJ= main.o logo.o logger.o help.o os_info.o test_gtk.o

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
	$(CC) $(CFLAGS) -c utils/os_info.c
test_gtk.o: commands/test_gtk.c
	$(CC) $(CFLAGS) -c commands/test_gtk.c $(LDLIBS)
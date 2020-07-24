#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "update_check.h"
#include "logger.h"

int checkForUpdate(char ver[10]){
    int sock;
    struct sockaddr_in server;
    char server_reply[2000];

    //Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if( sock == -1){
        printf("Error while creating socket.");
        logger("Error while creating socket");
    }
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 34000 );

    //Connect to Server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("Error. Connnection failed.");
        logger("[ERROR] Connection to update server failed.");
        return 1;
    }

        if( send(sock, ver, strlen(ver), 0) < 0){
        puts("Error while communicating with server.");
        logger("[ERROR] Send to server failed.");
    }

    if( recv(sock, server_reply, 2000, 0) < 0){
        puts("Error while communicating with server.");
        logger("[ERROR] Receive from server failed.");
    }
    if(!strcmp(server_reply, "VERSION_OUTDATED")){
        printf("\033[0;31mYour client is outdated. Please update your client.\033[0m\n");
        logger("[WARNING] Client is outdated.");
    }

    if(!strcmp(server_reply, "VERSION_OK")){
        logger("[INFO] Client is up-to-date.");
    }
    close(sock);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "update_check.h"
#include "logger.h"

#define SERVER_IP "127.0.0.1"

int checkForUpdate(char ver[10]){
    int sock;
    struct sockaddr_in server;
    char server_reply[2000];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if( sock == -1){
        printf("Error while creating socket.");
        logger("Error while creating socket");
    }
    
    server.sin_addr.s_addr = inet_addr(SERVER_IP); //Set the IP address of the server
    server.sin_family = AF_INET;
    server.sin_port = htons( 34000 ); //Set the server port

    //Connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("Error. Connnection to update server failed.");
        logger("[ERROR] Connection to update server failed.");
        return 1;
    }
    //Send message
    if( send(sock, ver, strlen(ver), 0) < 0){
        puts("Error while communicating with server.");
        logger("[ERROR] Send to server failed.");
    }
    //Receive response
    if( recv(sock, server_reply, 2000, 0) < 0){
        puts("Error while communicating with server.");
        logger("[ERROR] Receive from server failed.");
    }
    //Say that client outdated
    if(!strcmp(server_reply, "VERSION_OUTDATED")){
        printf("\033[0;31mYour client is outdated. Please update your client.\033[0m\n");
        logger("[WARNING] Client is outdated.");
    }
    //Say that client is up-to-date
    if(!strcmp(server_reply, "VERSION_OK")){
        logger("[INFO] Client is up-to-date.");
    }
    close(sock); //Close the socket
    return 0;
}
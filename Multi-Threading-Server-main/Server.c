#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <pthread.h>

#define TRUE 1
/*
 * This is the function we are giving to the new thread
 */
void *newFunc(void *sock){
    int sockId = *((int*)sock);
    free(sock);
    send(sockId, "Hello, world!", 13, 0);
    close(sockId);
}

int main(int argc, char const* argv[]){
    // create server socket similar to what was done in
    // client program
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);
    // define server address
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(3490);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the specified IP and port
    bind(servSockD, (struct sockaddr*)&servAddr,sizeof(servAddr));

    // listen for connections
    listen(servSockD, 10);
    while (TRUE){
        // integer to hold client socket.
        int clientSocket = accept(servSockD, NULL, NULL);
        pthread_t newThread;
        int *newSock = malloc(sizeof (int));
        *newSock = clientSocket;
        pthread_create(&newThread,NULL, newFunc,newSock);
    }
    return 0;
}
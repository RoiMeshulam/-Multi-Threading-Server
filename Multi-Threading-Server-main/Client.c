#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <netinet/in.h> //structure for storing address information
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>

#define TRUE 1
#define MAX_CMD_SIZE 1024

int main() {
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port= htons(3490); // use some unused port number
    servAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr,sizeof(servAddr));

    if (connectStatus == -1) {
        printf("Error...\n");
        return;
    }
    //Accepting data from the server
    char serverData[255];
    int numbytes;
    numbytes = recv(sockD, serverData, sizeof(serverData), 0);
    serverData[numbytes] = '\0';
    printf("%s\n",serverData);
    return 0;
}

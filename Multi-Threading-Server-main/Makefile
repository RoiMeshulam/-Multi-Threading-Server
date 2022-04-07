CC=gcc
AR=ar
FLAGS= -Wall -g

all: client server oserver oclient
original: oserver oclient
new: client server

client:  Client.o
	$(CC) $(FLAGS) -o Client Client.o

server:  Server.o
	$(CC) $(FLAGS) -pthread -o Server Server.o

oserver:  OriginalServer.o
	$(CC) $(FLAGS) -o OriginalServer OriginalServer.o

oclient:  OriginalClient.o
	$(CC) $(FLAGS) -o OriginalClient OriginalClient.o

Server.o: Server.c
	$(CC) $(FLAGS) -pthread -c Server.c

OriginalServer.o: OriginalServer.c
	$(CC) $(FLAGS) -c OriginalServer.c

Client.o: Client.c
	$(CC) $(FLAGS) -c Client.c

OriginalClient.o: OriginalClient.c
	$(CC) $(FLAGS) -c OriginalClient.c

.PHONY: clean all
clean:
	rm -f *.o Client Server OriginalServer OriginalClient
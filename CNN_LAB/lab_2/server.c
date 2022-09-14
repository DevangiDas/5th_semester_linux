// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT	 8080
#define MAXLINE 1024
	
// Driver code
int main() {
	int sockfd;
	
	int x,y,z,x1,y1,n;
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(8080);
		
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int len=sizeof(cliaddr);
	listen(sockfd,5);
	
	x1=recvfrom(sockfd, &x, sizeof(int), MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);
	y1=recvfrom(sockfd, &y, sizeof(int), MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);		
	printf("Two nos received\n");
	z=x+y;
	
	
	
	sendto(sockfd,&z, sizeof(int),
		MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
			len);
	printf("Sum sent\n");
		
	return 0;
}

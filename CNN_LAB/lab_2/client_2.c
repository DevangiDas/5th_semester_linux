 // Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Driver code
int main() {
int sockfd,x,y;
char buffer[MAXLINE];
char buffer2[MAXLINE];
char * hello="Hello server\n";
int choice,n2;

struct sockaddr_in servaddr;


if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
perror("socket creation failed");
exit(EXIT_FAILURE);
}

memset(&servaddr, 0, sizeof(servaddr));

// Filling server information
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(PORT);
servaddr.sin_addr.s_addr = INADDR_ANY;
int n,len,r,res;
len=sizeof(servaddr);
sendto(sockfd, (char *)hello, strlen(hello),MSG_CONFIRM,(const struct sockaddr *)&servaddr, len);
n=recvfrom(sockfd, (char*)buffer,MAXLINE, MSG_WAITALL,(struct sockaddr *)&servaddr, &len);
buffer[n]='\0';
printf("Server: %s\n",buffer);
scanf("%d",&choice);
sendto(sockfd, &choice, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&servaddr, len);
printf("Enter two nos\n");
scanf("%d%d",&x,&y);
sendto(sockfd, &x, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&servaddr, len);
sendto(sockfd, &y, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&servaddr, len);
r=recvfrom(sockfd, &res,sizeof(int), MSG_WAITALL,(struct sockaddr *)&servaddr, &len);
printf("The result is %d\n",res);

close(sockfd);
return 0;
}

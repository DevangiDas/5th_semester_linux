#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<time.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
int sockfd;
char buffer[MAXLINE];
char *msg = "Enter your choice \n1.addition 2.substraction 3.multiplication 4.division\n";

struct sockaddr_in servaddr, cliaddr;


if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
perror("socket creation failed");
exit(EXIT_FAILURE);
}

memset(&servaddr, 0, sizeof(servaddr));
memset(&cliaddr, 0, sizeof(cliaddr));


servaddr.sin_family = AF_INET; // IPv4
servaddr.sin_addr.s_addr = INADDR_ANY;
servaddr.sin_port = htons(PORT);


if ( bind(sockfd, (const struct sockaddr *)&servaddr,
sizeof(servaddr)) < 0 )
{
perror("bind failed");
exit(EXIT_FAILURE);
}

int len, n,ch1,choice,x,y,x1,y1,result;

len = sizeof(cliaddr);
n=recvfrom(sockfd, (char*)buffer,MAXLINE, MSG_WAITALL,(struct sockaddr *)&cliaddr, &len);
buffer[n]='\0';
printf("Client:%s",buffer);
sendto(sockfd, (char *)msg, strlen(msg),MSG_CONFIRM,(const struct sockaddr *)&cliaddr, len);
ch1=recvfrom(sockfd, &choice,sizeof(choice), MSG_WAITALL,(struct sockaddr *)&cliaddr, &len);
x1=recvfrom(sockfd, &x,sizeof(int), MSG_WAITALL,(struct sockaddr *)&cliaddr, &len);
y1=recvfrom(sockfd, &y,sizeof(int), MSG_WAITALL,(struct sockaddr *)&cliaddr, &len);
//printf("%d %d",x,y);
switch(choice){
	case 1:result=x+y;
	sendto(sockfd, &result, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&cliaddr, len);
	break;
	case 2:result=x-y;
	sendto(sockfd, &result, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&cliaddr, len);
	break;
	
	case 3:result=x*y;
	sendto(sockfd, &result, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&cliaddr, len);
	break;
	
	case 4:result=x/y;
	sendto(sockfd, &result, sizeof(int),MSG_CONFIRM,(const struct sockaddr *)&cliaddr, len);
	break;
	
	
	
}
printf("Result send\n");
close(sockfd);
return 0;
}

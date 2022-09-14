//server-side

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
int main()
{
  int sockfd;
  sockfd = socket(AF_INET,SOCK_DGRAM,0);
  if(sockfd<0)
  {
    printf("Socket Failure\n");
    exit(1);
    }
    struct sockaddr_in server_addr,client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    int bindfd;
    bindfd = bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(bindfd<0)
    {
      printf("Bind Failure");
      exit(1);
    }
    listen(sockfd, 1);
    char buff[100];
    socklen_t addr_size;
    addr_size = sizeof(client_addr);
    bzero(buff,100);
    recvfrom(sockfd,buff,100,0,(struct sockaddr *)&client_addr,&addr_size);

    char *userName = strtok(buff, ",");
    int day = atoi(strtok(NULL, " -"));
    int month = atoi(strtok(NULL, " -"));
    int year = atoi(strtok(NULL, " -"));
    size_t userName_length = strlen(buff);
    size_t age = 2022 - year;


    size_t vowels = 0;
    for(char *s = userName; *s; ++s)
        if(strchr("aeiou", tolower((unsigned char)*s)))
            ++vowels;
    
    sprintf(buff, " length: %d\n vowels: %d\n age: %d\n", userName_length, vowels, age);

    sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&client_addr,sizeof(client_addr));
    
    return 0;
    
  }


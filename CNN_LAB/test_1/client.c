//client side implenentation
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
 #include <stdlib.h>
int main()
{
    int sockfd;
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd<0) {
    printf("Socket Failure\n");
    exit(1);
    }
    struct sockaddr_in addr,client_addr;
    socklen_t addr_size;
    addr_size = sizeof(client_addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    char str[100];

    puts("DEVANGI DAS, 10-12-2001");
    fgets(str,sizeof(str),stdin);
    sendto(sockfd,str,sizeof(str),0,(struct sockaddr *)&addr,sizeof(addr));
    recvfrom(sockfd, str, 100, 0, (struct sockaddr *)&client_addr, &addr_size);
    puts(str);
    
    return 0;
}


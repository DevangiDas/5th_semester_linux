//client

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

int main () {
    struct sockaddr_in server;
    char str[256];
    char buf[256];
    char a1[256];
    char b1[256];
    char c1[256];
    int a,b,c;

    int sock1204 = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    connect(sock1204, (struct sockaddr *)&server, sizeof(server));

    printf("Enter the PCM Marks : ");
    scanf("%d %d %d",&a,&b,&c);
    
    
    send(sock1204, &a, sizeof(int), 0);
    send(sock1204, &b, sizeof(int), 0);
    send(sock1204, &c, sizeof(int), 0);
    
    recv(sock1204, a1, sizeof(a1), 0);
    printf("%s\n",a1);
    recv(sock1204, b1, sizeof(b1), 0);
    printf("%s\n",b1);
    recv(sock1204, c1, sizeof(c1), 0);
    printf("%s\n",c1);
    close(sock1204);

    return 0;
}

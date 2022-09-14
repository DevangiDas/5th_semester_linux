//server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main () {
    struct sockaddr_in server, client;
    char buf[256];
    char str[256];
    char a1[256];
    char b1[256];
    char c1[256];
    int a,b,c;
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 1);

        int len = sizeof(client);
        int sock1204 = accept(sock, (struct sockaddr *)&client, &len);

        recv(sock1204, &a, sizeof(int), 0);
        printf("%d\n", a);
        recv(sock1204, &b, sizeof(int), 0);
        printf("%d\n", b);
	recv(sock1204, &c, sizeof(int), 0);
        printf("%d\n", c);
        
        if(a<=100&&a>=91)
        	strcpy(a1, "P : O");
        if(a<=90&&a>=81)
        	strcpy(a1, "P : E");
        if(a<=80&&a>=71)
        	strcpy(a1, "P : A");
        if(a<=70&&a>=61)
        	strcpy(a1, "P : B");
        if(a<=60&&a>=51)
        	strcpy(a1, "P : C");
        if(a<=50)
        	strcpy(a1, "P : F");
        send(sock1204, a1, sizeof(a1), 0);
        
                if(b<=100&&b>=91)
        	strcpy(b1, "C : O");
        if(b<=90&&b>=81)
        	strcpy(b1, "C : E");
        if(b<=80&&b>=71)
        	strcpy(b1, "C : A");
        if(b<=70&&b>=61)
        	strcpy(b1, "C : B");
        if(b<=60&&b>=51)
        	strcpy(b1, "C : C");
        if(b<=50)
        	strcpy(b1, "C : F");
        send(sock1204, b1, sizeof(b1), 0);
        
                if(c<=100&&c>=91)
        	strcpy(c1, "P : O");
        if(c<=90&&c>=81)
        	strcpy(c1, "P : E");
        if(c<=80&&c>=71)
        	strcpy(c1, "P : A");
        if(c<=70&&c>=61)
        	strcpy(c1, "P : B");
        if(c<=60&&c>=51)
        	strcpy(c1, "P : C");
        if(c<=50)
        	strcpy(c1, "P : F");
        send(sock1204, c1, sizeof(c1), 0);
        
        printf("Successfully Send\n");
        
        close(sock1204);

    close(sock);

    return 0;
}

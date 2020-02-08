#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment (lib,"ws2_32.lib")

int main (int argc , char *argv[])
{
    //initialize windows socket
    WSADATA  wsa;
    SOCKET s;
    struct sockaddr_in server ;
    printf ("\nInitialising winsock ...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) !=0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf ("Initialised.\n");

    //CREATE SOCKET
    if ((s =socket(AF_INET , SOCK_STREAM , 0 ))==INVALID_SOCKET)
    {
        printf("Could not create socket : %d ", WSAGetLastError());
    }
    printf("Socket created.\n");

    server.sin_family = AF_INET ; //ADDR IPV4
    server.sin_port = htons(80);
    server.sin_addr.s_addr = inet_addr("184.106.153.149");

    connect(s,(struct sockaddr *)&server ,sizeof(server));
    if(connect(s,(struct sockaddr*)&server , sizeof(server)),0)
    {
        puts("Connect Error");
    }
    else
    {
        puts("Connection Initialized Successfully.\n");
    }

     char message [200] = "GET https://api.thingspeak.com/update?api_key=UHKQPLTT2KVS9UJ5&field1=0\r\n\r\n" ;
     //printf("please  enter the temp :");
     //char message2 [10];
     //gets(message2);

     //strcat(message,message2);

    //send

     int x,i;
     for(i=1 ; i<=5 ; i++)
     {
     printf("please  enter the temp :");
     scanf ("%d",&x);
     sprintf(message, "GET https://api.thingspeak.com/update?api_key=UHKQPLTT2KVS9UJ5&field1=%d\r\n\r\n", x);
     send (s,message ,strlen (message),0);

     }
     //printf("%s \n",message);
     printf("done\n");

     closesocket(s);


}

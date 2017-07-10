// #include <stdio.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <netinet/in.h>
// #include <string.h>

// int main(){
//   int clientSocket;
//   char buffer[1024];
//   struct sockaddr_in serverAddr;
//   socklen_t addr_size;

//   /*---- Create the socket. The three arguments are: ----*/
//   /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
//   clientSocket = socket(AF_INET, SOCK_STREAM, 0);

//   /*---- Configure settings of the server address struct ----*/
//   /* Address family = Internet */
//   serverAddr.sin_family = AF_INET;
//   /* Set port number, using htons function to use proper byte order */
//   serverAddr.sin_port = htons(8888);
//   /* Set IP address to localhost */
//   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//   /* Set all bits of the padding field to 0 */
//   memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

//   /*---- Connect the socket to the server using the address struct ----*/
//   addr_size = sizeof serverAddr;
//   connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

//   /*---- Read the message from the server into the buffer ----*/
//   recv(clientSocket, buffer, 1024, 0);

//   /*---- Print the received message ----*/
//   printf("Data received: %s",buffer);

//   return 0;
// }

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  int sockfd = 0, n = 0;
  char recvBuff[1024];
  struct sockaddr_in serv_addr;

  if(argc != 2){
    printf("\n Usage: %s <ip of server> \n",argv[0]);
    return 1;
  }

  memset(recvBuff, '0',sizeof(recvBuff));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("\n Error : Could not create socket \n");
    return 1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8888);

  if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0){
    printf("\n inet_pton error occured\n");
    return 1;
  }

  if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
    printf("\n Error : Connect Failed \n");
    return 1;
  }

  while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0){
    recvBuff[n] = 0;
    if(fputs(recvBuff, stdout) == EOF){
      printf("\n Error : Fputs error\n");
    }
  }

  if(n < 0){
    printf("\n Read error \n");
  }

  return 0;
}
#include "ss.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

// int s_socket_server(){
//   int welcomeSocket, newSocket;
//   char buffer[1024];
//   struct sockaddr_in serverAddr;
//   struct sockaddr_storage serverStorage;
//   socklen_t addr_size;

//   /*---- Create the socket. The three arguments are: ----*/
//   /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
//   welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

//   /*---- Configure settings of the server address struct ----*/
//   /* Address family = Internet */
//   serverAddr.sin_family = AF_INET;
//   /* Set port number, using htons function to use proper byte order */
//   serverAddr.sin_port = htons(7891);
//   /* Set IP address to localhost */
//   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    Set all bits of the padding field to 0
//   memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

//   /*---- Bind the address struct to the socket ----*/
//   bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

//   /*---- Listen on the socket, with 5 max connection requests queued ----*/
//   if(listen(welcomeSocket,5)==0)
//     printf("Listening\n");
//   else
//     printf("Error\n");

//   /*---- Accept call creates a new socket for the incoming connection ----*/
//   addr_size = sizeof serverStorage;
//   newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

//   /*---- Send message to the socket of the incoming connection ----*/
//   strcpy(buffer,"Hello World\n");
//   send(newSocket,buffer,13,0);

//   return 0;
// }

int s_create_server(s_server_config* ssc){
  server = (s_socket*)malloc(sizeof(s_socket));
  memset(server, 0, sizeof(s_socket));

  memcpy(&server->ssc, ssc, sizeof(server->ssc));

  // server->ssc = ssc;
  buffer = (char*)malloc(sizeof(char) * ssc->buffer_size);

  memset(buffer, 0, sizeof(sizeof(char) * ssc->buffer_size));
  memset(&server->server_addr, 0, sizeof(server->server_addr));

  server->lfd = socket(ssc->i_family, ssc->s_type, ssc->protocol);
  server->server_addr.sin_family = ssc->i_family;
  server->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server->server_addr.sin_port = ssc->port;

  bind(server->lfd, (struct sockaddr*)&server->server_addr, sizeof(server->server_addr));
  return server->lfd;
}

void s_start_server(){
  listen(server->lfd, server->ssc.max_cli);
  while(1) {
    printf("Sanchaar is waiting for clients at port %d\n", server->server_addr.sin_port);
    server->cfd = accept(server->lfd, (struct sockaddr*)NULL, NULL);
    printf("Client connected %d\n", server->cfd);

    close(server->cfd);
    sleep(1);
  }
}

int s_stop_server(s_server_config* ssc){
  return 0;
}

int s_block_channel(const char* channel_name){
  return 0;
}

int s_unblock_channel(const char* channel_name){
  return 0;
}

int s_block_ip(uint32_t ip){
  return 0;
}

int s_unblock_ip(uint32_t ip){
  return 0;
}


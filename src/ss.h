#ifndef P_SS_H
#define P_SS_H

#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


// socket server configuration for user
typedef struct s_server_config {
  uint32_t buffer_size;
  uint16_t port;
  int i_family;
  int s_type;
  int protocol;
  uint32_t max_cli;
} s_server_config;

typedef struct s_channels {

} s_channels;

typedef struct s_client {
  int fd;
  struct sockaddr_in client_addr;
} s_client;

// socket structue of the PUB/SUB server
typedef struct s_socket {
  int lfd;
  int cfd;
  // char buffer[1024];
  struct sockaddr_in server_addr;
  // struct sockaddr_storage server_storage;
  // socklen_t addr_size;
  s_server_config ssc;
} s_socket;

s_socket* server;
char* buffer;

// test function
// int s_socket_server(void);

int s_create_server(s_server_config*);
void s_start_server();

int s_stop_server(s_server_config*);

int s_block_channel(const char* channel_name);
int s_unblock_channel(const char* channel_name);

int s_block_ip(uint32_t ip);
int s_unblock_ip(uint32_t ip);

#endif
#ifndef P_SS_H
#define P_SS_H

// test function
int socket_server(void);

// socket server configuration for user
struct p_server_config {
  uint32_t buffer_size;
  uint16_t port;
  int fd;
};

struct p_channels {

}

struct p_client {
  int fd;
  struct sockaddr_in client_addr;
};

// socket structue of the PUB/SUB server
struct p_socket {
  int welcome_socket, new_socket;
  char buffer[1024];
  struct sockaddr_in server_addr;
  struct sockaddr_storage server_storage;
  socklen_t addr_size;
};

int p_start_server(struct p_server_config psc);
int p_stop_server(struct p_server_config psc);

int p_block_channel(const char* channel_name);
int p_unblock_channel(const char* channel_name);

int p_block_ip(uint32_t ip);
int p_unblock_ip(uint32_t ip);

#endif
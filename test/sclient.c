#include "../src/ss.h"
#include <stdlib.h>
#include <string.h>

int main() {
  s_server_config serv_config;
  // memset(serv_config, 0, sizeof(s_server_config));

  serv_config.buffer_size = 1024;
  serv_config.port = 8888;
  serv_config.i_family = AF_INET;
  serv_config.s_type = SOCK_STREAM;
  serv_config.protocol = 0;
  serv_config.max_cli = 10;

  int rc = s_create_server(&serv_config);
  printf("rc = %d\n", rc);
  s_start_server();

  return 0;
}
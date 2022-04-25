#include "webserv.hpp"
#include "debug.hpp"

char response[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html><html><head><title>webserv</title>"
"<style>body { background-color: #fff }"
"h1 { font-size:4cm; text-align: center; color: black;"
" text-shadow: 0 0 2mm red}</style></head>"
"<body><h1>Hello world!</h1></body></html>\r\n";

int main()
{
  int one = 1, client_fd;
  struct sockaddr_in svr_addr, cli_addr;
  socklen_t sin_len = sizeof(cli_addr);
 
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    std::cout << "Error: Can't open socket" << std::endl;
 
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));
 
  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(PORT);
 
  if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
    close(sock);
    std::cout << "Error: Can't bind" << std::endl;
  }
 
  listen(sock, 5);
  while (1) {
    if ((client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len)) == -1)
      std::cout << "Can't accept" << std::endl;

    #ifdef __DEBUG
      std::cout << "Got a connection!" << std::endl;
    #endif
 
    write(client_fd, response, sizeof(response) - 1); // not allowed
    close(client_fd); // not allowed
  }
}
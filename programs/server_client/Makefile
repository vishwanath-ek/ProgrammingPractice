CFLAGS = -Wall -Wextra -g

all: server client

server: tcp_server.c tcp_send_recv.c
	gcc $(CFLAGS) tcp_server.c tcp_send_recv.c -o server

client: tcp_client.c tcp_send_recv.c
	gcc $(CFLAGS) tcp_client.c tcp_send_recv.c -o client

clean:
	rm server client

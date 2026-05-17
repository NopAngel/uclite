#ifndef UCLITE_NETWORK_H
#define UCLITE_NETWORK_H

// Standard families and types for sockets in Linux
#define AF_INET     2  // IPv4 Internet protocols
#define SOCK_STREAM 1  // Flow-oriented connection (TCP)

int socket(int domain, int type, int protocol);

#endif

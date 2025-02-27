#ifndef PEER2PEER_H_INCLUDED
#define PEER2PEER_H_INCLUDED
 // C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>
#include "Parser.h"
#include "StringFunctions.h"
#include "Node.h"
#include "NodesLoader.h"
#include "FileRAW.h"
#include "TorrentLoader.h"
#include "Torrent.h"
#include "RarestChunkFirst.h"
#include "AddressGetter.h"

int open_socket();
int init_thread();
void bind_to_port(int socket, int port);
void server_process(int PORT);
void client_process(int PORT);
int writeSocket(int file_descriptor, char *buffer, int len);
int readSocket(int file_descriptor, char *buffer, int len);
void p2p();

#endif


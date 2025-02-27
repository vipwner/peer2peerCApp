# VARIABLES
CC = gcc
CFLAGS = -Wall -Wextra -g
PRO_SERVER = p2p_server
PRO_CLIENT = p2p_client

# Source files
P2P = Peer2Peer
NOL = NodesLoader
STRF = StringFunctions
PAR = Parser
FRAW = FileRAW
REB = ChunkFunctions
TOR = TorrentLoader
RCF = RarestChunkFirst
GN = AddressGetter

# Object files
OBJS = $(P2P).o $(NOL).o $(STRF).o $(PAR).o $(FRAW).o $(REB).o $(TOR).o $(RCF).o $(GN).o

# Compile all targets
all: $(PRO_SERVER) $(PRO_CLIENT)

# Compile the server
$(PRO_SERVER): $(OBJS) p2p_server.o
	$(CC) $(OBJS) p2p_server.o -o $(PRO_SERVER) $(CFLAGS)

p2p_server.o: p2p_server.c
	$(CC) -c p2p_server.c -o p2p_server.o $(CFLAGS)

# Compile the client
$(PRO_CLIENT): $(OBJS) p2p_client.o
	$(CC) $(OBJS) p2p_client.o -o $(PRO_CLIENT) $(CFLAGS)

p2p_client.o: p2p_client.c
	$(CC) -c p2p_client.c -o p2p_client.o $(CFLAGS)

# Compile shared object files
$(P2P).o: $(P2P).c
	$(CC) -c $(P2P).c -o $(P2P).o $(CFLAGS)

$(NOL).o: $(NOL).c
	$(CC) -c $(NOL).c -o $(NOL).o $(CFLAGS)

$(STRF).o: $(STRF).c
	$(CC) -c $(STRF).c -o $(STRF).o $(CFLAGS)

$(PAR).o: $(PAR).c
	$(CC) -c $(PAR).c -o $(PAR).o $(CFLAGS)

$(FRAW).o: $(FRAW).c
	$(CC) -c $(FRAW).c -o $(FRAW).o $(CFLAGS)

$(REB).o: $(REB).c
	$(CC) -c $(REB).c -o $(REB).o $(CFLAGS)

$(TOR).o: $(TOR).c
	$(CC) -c $(TOR).c -o $(TOR).o $(CFLAGS)

$(RCF).o: $(RCF).c
	$(CC) -c $(RCF).c -o $(RCF).o $(CFLAGS)

$(GN).o: $(GN).c
	$(CC) -c $(GN).c -o $(GN).o $(CFLAGS)

# Clean up
clean:
	rm -rf *.o p2p_server p2p_client

# VARIABLES
# C Compiler.
CC = gcc
# Program name.
PRO = Program
# Files...
MAIN = Main
P2P = Peer2Peer
NOL = NodesLoader
STRF = StringFunctions
PAR = Parser
FRAW = FileRAW
REB = ChunkFunctions
TOR = TorrentLoader
RCF = RarestChunkFirst
GN = AddressGetter
# MAKEFILE
all: $(PRO)
$(PRO): $(MAIN).o $(P2P).o $(NOL).o $(STRF).o $(PAR).o $(FRAW).o  $(REB).o $(TOR).o $(RCF).o $(GN).o
	$(CC) $(MAIN).o $(P2P).o $(NOL).o $(STRF).o $(PAR).o $(FRAW).o $(REB).o $(TOR).o $(RCF).o $(GN).o -o $(PRO)
$(MAIN).o: $(MAIN).c
	$(CC) -c $(MAIN).c -o $(MAIN).o 
$(P2P).o: $(P2P).c
	$(CC) -c $(P2P).c -o $(P2P).o
$(NOL).O: $(NOL).c
	$(CC) -c $(NOL).c -o $(NOL).o
$(STRF).o: $(STRF).c
	$(CC) -c $(STRF).c -o $(STRF).o
$(PAR).o: $(PAR).c
	$(CC) -c $(PAR).c -o $(PAR).o
$(FRAW).o: $(FRAW).c
	$(CC) -c $(FRAW).c -o $(FRAW).o
$(REB).o: $(REB).c
	$(CC) -c $(REB).c -o $(REB).o
$(TOR).o: $(TOR).c
	$(CC) -c $(TOR).c -o $(TOR).o
$(RCF).o: $(RCF).c
	$(CC) -c $(RCF).c -o $(RCF).o
$(GN).o: $(GN).c
	$(CC) -c $(GN).c -o $(GN).o
clean:
	rm -rf *.o Program
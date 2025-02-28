# VARIABLES
# C Compiler.
CC = gcc
# Program name.
PRO = torrent_generator
# Files...
MAIN = Main
TORG = TorrentGenerator
VIEW = View
SHA = SHACalculator
STRF = StringFunctions
ADG = AddressGetter
# MAKEFILE
all: $(PRO)
$(PRO): $(MAIN).o $(TORG).o $(VIEW).o $(SHA).o $(STRF).o $(ADG).o 
	$(CC) $(MAIN).o $(TORG).o $(VIEW).o $(SHA).o $(STRF).o $(ADG).o -o $(PRO)
$(MAIN).o: $(MAIN).c
	$(CC) -c $(MAIN).c -o $(MAIN).o
$(TORG).o: $(TORG).c
	$(CC) -c $(TORG).c -o $(TORG).o
$(VIEW).o: $(VIEW).c
	$(CC) -c $(VIEW).c -o $(VIEW).o
$(SHA).o: $(SHA).c
	$(CC) -c $(SHA).c -o $(SHA).o
$(STRF).o: $(STRF).c
	$(CC) -c $(STRF).c -o $(STRF).o
$(ADG).o: $(ADG).c
	$(CC) -c $(ADG).c -o $(ADG).o
clean:
	rm -rf *.o $(PRO)

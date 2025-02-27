#include "Peer2Peer.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int PORT = 7024;

    // Prevent the client from running without an interactive shell
    if (!isatty(fileno(stdin))) {
        printf("Error: Client cannot run in non-interactive mode.\n");
        return EXIT_FAILURE;
    }

    printf("Starting P2P Client. Type commands:\n");
    
    while (1) {
        client_process(PORT);
    }

    return 0;
}

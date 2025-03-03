#include "Peer2Peer.h"

int main()
{
    const int PORT = 7024;
    printf("Starting P2P Server on port %d...\n", PORT);
    server_process(PORT);
    return 0;
}

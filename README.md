# BitTorrent-like File Transfer Application

This is a C implementation of a **peer-to-peer (P2P) file transfer application**, drawing inspiration from the BitTorrent protocol [1, 2]. The application facilitates the transfer of files across a network where users simultaneously download and upload file fragments [3].

## Key Features

*   **Chunk-based file transfer:** Files are divided into chunks of 512 KB for transfer and storage [1].
*   **P2P network:** The application operates within a P2P network, where each node acts as both a client and a server [1]. The network has a mesh-like structure where each node knows the identity of other nodes in the network [4].
*   ***.torrent files:**  Uses *.torrent files to specify the shared file's name and chunk information, including cryptographic hashes and chunk positions [5].
*   **Rarest-Chunk-First heuristic:** Implements the Rarest-Chunk-First algorithm for chunk selection during downloads [6, 7]. This involves selecting the chunks with the fewest copies across the network to optimise distribution [7].
*   **Network flooding for chunk discovery:** Nodes flood the network with requests to find which nodes possess the required chunks [6].
*   **Basic network operations:** Connecting to multiple nodes, receiving new connections, sending messages to peers [4, 8].

## Usage

TODO


## Implementation Details

*   **Language:** C
*   **Platform:** Unix -- Will see if I can dockerized this project
*   **Communication:** TCP

## Limitations

*   The current implementation does not include a mechanism to notify other nodes when a new chunk has been acquired for sharing [9].

## Structure

The application operates in three stages: **Connection, Search, and Download** [8].

## Credits

The design is inspired by BitTorrent [2, 3].

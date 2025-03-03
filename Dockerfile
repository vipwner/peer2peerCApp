# Use Debian with GCC
FROM debian:latest

# Install dependencies
RUN apt-get update && apt-get install -y gcc make valgrind inotify-tools astyle && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source files
COPY p2p_app /app/p2p_app
COPY torrent_generator /app/torrent_generator

# Build the P2P app (Server & Client)
WORKDIR /app/p2p_app
RUN make && mv p2p_server p2p_client /usr/local/bin/

# Build the Torrent Generator
WORKDIR /app/torrent_generator
RUN make && mv torrent_generator /usr/local/bin/

# Set default working directory
WORKDIR /app

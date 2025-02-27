#include "Peer2Peer.h"

int open_socket()
{
	int sock = socket(PF_INET, SOCK_STREAM, 0); // El 0 indica que el SO escoge el protocolo.
	if(sock == -1){
		printf("Error al abrir socket.\n");
		return -1;
	}
	return sock;
}

pid_t init_thread()
{
	pid_t pid = fork();
	if(pid == -1){
		printf("Error al inicializar los procesos Cliente/Servidor.\n");
	}
	return pid;
}

void bind_to_port(int socket, int port)
{
	struct sockaddr_in socketInput;
	socketInput.sin_family		= PF_INET;
	socketInput.sin_port		= (in_port_t)htons(port);
	socketInput.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int)) == -1){
		error(">> No se puede conectar nadie mas.\n");
	}
	int c = bind(socket, (struct sockaddr*) &socketInput, sizeof(socketInput));
	if(c == -1){
		perror("No se puede enlazar al puerto : La direccion ya esta en uso.");
	}
}

void server_process(int PORT)
{	
	int MAX_BUFF_COMMAND = 100;	
	int MAX_CONTAINER_NUM = 99;	
	int MAX_MESSAGE_TAM = 512*1024; // 524288. 
	int listener = open_socket(); // Socket que escucha los clientes que se conectan.	
	if(listener == -1){ // Indica que hay un error.
		printf("Error en listener.\n");
		return; // Terminamos la ejecucion...
	}
	bind_to_port(listener, PORT);
	if(listen (listener, 10) == -1){ // el 10 indica el maximo de usuarios.
		printf("No es posible escuchar en este puerto.\n");
		return; // Terminamos la ejecucion...
	}
	// Anunciamos que el par esta enlazado al puerto y escuchando a posibles clientes...
	printf("PAR Enlazado al puerto.\n");
	char message_fromClient[MAX_BUFF_COMMAND];
	while(1){
		struct sockaddr_storage socket_client; 
		unsigned int address_size = sizeof(socket_client);
		// Aqui se produce la espera...
		int connect = accept(listener, (struct sockaddr*) &socket_client, &address_size);
		// Validamos que la conexion sea exitosa.		
		if(connect == -1){
			printf("No se puede atender el cliente.\n");
		}	
		// Recibimos el mensaje del cliente...
		int read_size = readSocket(connect, message_fromClient, MAX_BUFF_COMMAND);
		// Validamos el mensaje del cliente...
		if(read_size < 0){	
			perror("Imposible recibir mensaje. Error");		
		}
		printf("Mensaje Cliente: %s\n", message_fromClient);
		// Aqui se debe gestionar las acciones de comando una vez se verifico la recepcion del mensaje con exito...
		//printf("Verificamos el comando: %s\n", message_fromClient);


		pid_t pid = init_thread();
		if(pid){
			// Do nothing...
			if(validateEXIT(message_fromClient)){
				puts("SERVIDOR FUERA.");
				return;
			}
		}else{
		

		if(validateGET(message_fromClient))
		{
			printf("%s\n", "Comando GET SERVER");
			char message_serverProcess[MAX_BUFF_COMMAND]; // Contenedor de mensajes...
			sprintf(message_serverProcess, "%s", "HAS <chunklist>");
			int send_ = writeSocket(connect, message_serverProcess, MAX_BUFF_COMMAND);
			if(send_ < 0){
				perror("Imposible enviar comando HAS. Error ");
			}
			// Cargamos la lista de chunks...
			char chunkList[MAX_MESSAGE_TAM]; // Cotenido del archivo.
			readFile("ChunkList.txt", chunkList, MAX_MESSAGE_TAM);
			send_ = writeSocket(connect, chunkList, MAX_MESSAGE_TAM);
			if(send_ < 0){
				perror("Imposible enviar lista de chunks. Error ");
			}
		}
		else if(validateSENDME(message_fromClient))
		{
			printf("%s\n", "Comando SENDME SERVER");
			// Se procede a enviar el chunk solicitado...
			char SHA[MAX_BUFF_COMMAND];
			strncpy(SHA, message_fromClient + 7, strlen(message_fromClient));
			printf("SHA OBTENIDO: %s\n", SHA);
			char id[MAX_BUFF_COMMAND];
			int getId_ok = getIDChunk(id, SHA);
			if(getId_ok == -1){
				perror("Error al enviar chunk. ");
				break;
			}
			// Antes de enviar el chunk se avisa la longitud del chunk.
			int fileSize = getFileSize(id);
			char messageTamFile[MAX_BUFF_COMMAND];
			sprintf(messageTamFile, "%d", fileSize);
			int send_ = writeSocket(connect, messageTamFile, MAX_BUFF_COMMAND);
			if(send_ < 0){
				perror("Imposible enviar tamaño del chunk. Error ");
				break;
			}
			// Procedemos a enviar el chunk...			
			char chunkContent[fileSize];
			readFile(id, chunkContent, fileSize);
			//printf("CONTENIDO CHUNK SERVIDOR: %s", chunkContent);
			//send_ = send(connect, chunkContent, sizeof(chunkContent), 0);
			//send_ = write(connect, chunkContent, 524288);
			send_ = writeSocket(connect, chunkContent, fileSize);
			printf("BYTES ENVIADOS DEL SOCKET SERVIDOR: %d\n", send_);
			//printf("BYTES ENVIADOS DEL SOCKET SERVIDOR: %d\n", send_);
			if(send_ < 0){
				perror("Imposible enviar el chunk. Error ");
				break;
			}			
		}else if(validateEXIT(message_fromClient)){
			puts("SERVIDOR FUERA.");
			exit(EXIT_SUCCESS);
		}
		else{
			perror("COMANDO INVALIDO. Error ");
		}	
		// ..	
		close(connect); // Cerramos la conexion con el proceso cliente.
		memset(message_fromClient, 0, MAX_BUFF_COMMAND);
		}
	}
}

void client_process(int PORT)
{	
	int MAX_BUFF_COMMAND = 100;	
	int MAX_CONTAINER_NUM = 99;	
	int MAX_MESSAGE_TAM = 512*1024; // 524288.
	// Obtenemos el comando.
	char message_clientProcess[MAX_BUFF_COMMAND];
	printf("%s", ">> ");
	fgets(message_clientProcess, sizeof(message_clientProcess), stdin);
	fflush(stdin);
	puts("Paso por linea 117.");
	message_clientProcess[strlen(message_clientProcess) - 1] = '\0';
	puts("Paso por linea 123");
	printf("Comando Escrito: %s\n", message_clientProcess);
	if(validateGET(message_clientProcess))
	{
		printf("%s\n", "Comando GET CLIENT");
		// Cargamos el .torrent y verificamos que el archivo pedido exista.
		Torrent torrent;
		char* fileName;
		fileName = substr(message_clientProcess,4,0);
		torrent.torrentFileName = fileName;
		torrent.chunks = (Chunk*) calloc (MAX_CONTAINER_NUM, sizeof(Chunk));
		int loadT_ok = loadTorrent(torrent.torrentFileName, torrent.chunks);
		if(loadT_ok == -1){
			perror("Error al cargar el torrent. Error ");
			return; // Detenemos la descarga...
		}
		torrent.chunksQ = loadT_ok;
		int it = 0;
		for(it; it < loadT_ok; it++){
			(torrent.chunks[it].SHA)[40] = '\0';
			printf("%d. PRUEBA DATOS torrent: %s\n", it, torrent.chunks[it].SHA);
			// Inicializamos el estado del chunk...
			torrent.chunks[it].status = 1; // 1 Indica que aun no se ha descargado, 0 lo contrario.
		}
		// Se enviar el comando a todos los nodos al interio de la red P2P.
		// Cargamos informacion de la lista de nodos.
		Node *nodesContainer;
		nodesContainer = (Node*) calloc (MAX_CONTAINER_NUM, sizeof(Node));
		int loadN_ok = loadNodes(nodesContainer);
		if(loadN_ok == -1){
			perror("Error al cargar archivo de nodos.. Error ");
			return; // Detenemos la descarga...
		}
		it = 0;
		for(it; it < loadN_ok; it++){
			(nodesContainer[it].portNode)[4] = '\0';
			printf("%d. PRUEBA DATOS nodos: %s, %s\n", it, nodesContainer[it].ipNode, nodesContainer[it].portNode);
		}
		it = 0; 
		int nodeCount = loadN_ok;//Cantidad de nodos.
		if(nodeCount == 0){
			perror("No hay nodos en la Red.");
			return;
		}
		for(it; it < nodeCount; it++){			
			printf("Nodo: %s\n", nodesContainer[it].idNode);
			// ----------------------------------------------------------------------------------------------------------------
			// Iniciamos el socket por el cual el proceso cliente enviara y recibira mensajes...
		    int listener =  socket(AF_INET,SOCK_STREAM,0);
			if(listener == -1){
				printf("Error al abrir socket.\n");
				return; // Terminamos la ejecucion del programa.
			}
			// Lo relacionado al par que se desea conectar...
			struct sockaddr_in server;
			server.sin_addr.s_addr = inet_addr(nodesContainer[it].ipNode); // Aquí se pone la IP del par con el cual se desea comunicar.
			server.sin_family = AF_INET;
			server.sin_port = htons(atoi(nodesContainer[it].portNode)); // El puerto del par con el que se desea comunicar.
			// Iniciamos la conexion al servidor.
			int connect_ = connect(listener, (struct sockaddr *)&server, sizeof(server));
			if(connect_ < 0){
				perror("Imposible realizar conexion. Error ");
				return; // Detenemos la descarga...
			}
			// -----------------------------------------------------------------------------------------------------------------
			// Una vez tengamos configurado el socket para realizar la conexion al nodo i entonces...
			int send_ = writeSocket(listener, message_clientProcess, MAX_BUFF_COMMAND);
			if(send_ < 0){
				perror("Imposible enviar comando GET. Error ");
				return; 
			}
			// Recibimos LA NOTIFICACION HAS DEL SERVIDOR
			char comand_HAS_Not[MAX_BUFF_COMMAND]; 
			int rcv_ = readSocket(listener, comand_HAS_Not, MAX_BUFF_COMMAND);
			if(rcv_ < 0){
				perror("Imposible recibir notifiacion comando HAS. Error ");
				return;
			}
			printf("Mensaje Servidor: %s\n", comand_HAS_Not);
			if(validateHAS(comand_HAS_Not)){
				printf("%s\n", "Comando HAS CLIENT");				
				// Nos preparamos para el envio de la lista de chunks...	
				char chunkList[MAX_MESSAGE_TAM]; // Cotenido del archivo.
				rcv_ = readSocket(listener, chunkList, MAX_MESSAGE_TAM);
				if(rcv_ < 0){
					perror("Imposible recibir la lista de chunks. Error ");
					return;
				}
				printf("Lista de Chunks del Nodo %d :\n%s", it + 1, chunkList);
				// ..
				int chunkListLen = strlen(chunkList);
				printf("Longitud de la lista de Chunks: %d\n", chunkListLen);
				nodesContainer[it].chunks = (Chunk*) calloc (MAX_CONTAINER_NUM + it + 1, sizeof(Chunk));
				int setCNode_ok = setChunksNode(chunkList, chunkListLen, nodesContainer[it].chunks);
				if(setCNode_ok == -1){
					perror("Imposible setear la lista de chunks. Error ");
					return;
				}
				nodesContainer[it].chunksQ = setCNode_ok;
				int it_in = 0;
				for(it_in; it_in < setCNode_ok; it_in++){
					(nodesContainer[it].chunks[it_in].SHA)[40] = '\0';
					printf("%d. PRUEBA DATOS nodes.chunks: %s\n", it_in, nodesContainer[it].chunks[it_in].SHA);
				}
			}
			close(listener);// Se cierra la conexion con cada nodo.	
		}
		//Empezamos la descarga del archivo.
		printf("Cantidad de chunks a Descargar: %d\n", torrent.chunksQ);	
		int incomplete_download = 1;
		it = 0;
		//while(1)
		for(it; it < torrent.chunksQ; it++)
		{
			pid_t pid = init_thread();
			if(pid){
				// Espera activa mientras se descargan los chunks...
				while(incomplete_download == 1){
					// Do nothing...
				}
			}else{

			//Armamos el comando sendme.
			char SEND_ME_COMAND[MAX_BUFF_COMMAND];
			memset(SEND_ME_COMAND, '0',sizeof(SEND_ME_COMAND));
			sprintf(SEND_ME_COMAND, "%s", "SENDME ");
			// Obtenemos el SHA y la posicion del chunk a descargar...
			// rarest_ok Determina cuando la descarga ha sido completada.
			char rarestSHA[40];
			int rarest_ok = getRarestChunkFirst(rarestSHA, torrent.chunks, torrent.chunksQ, nodesContainer, nodeCount);
			if(rarest_ok == -1){
				perror("Error al calcular el chunk a ser descargado. ");
				return;
			}	
			else if(rarest_ok == -2){
				// La descarga del archivo ha sido completada... Se rompe el ciclo.
				puts("Paso por linea 254.");
				incomplete_download = 0;
				break;
			}
			// Se cambia el estado del chunk a descargar...
			torrent.chunks[rarest_ok].status = 0;
			printf("Resultado getRarestChunkFirst(): %s\n", rarestSHA);
			strcat(SEND_ME_COMAND, rarestSHA);
			printf("Comando: %s\n", SEND_ME_COMAND);			
			// Buscamos el nodo con el Rarest-Chunk.
			char temp_id[MAX_BUFF_COMMAND];
			char temp_ip[MAX_BUFF_COMMAND];
			char temp_port[MAX_BUFF_COMMAND];
			int rarestNode_ok = searchNode(temp_id, temp_ip, temp_port, nodesContainer, nodeCount, rarestSHA);			
			if(rarestNode_ok == -1){
				perror("Error al obtener nodo con el chunk obtenido por el algoritmo RAREST-CHUNK-FIRST.");
				return;
			}
			Node nodeToCon;
			nodeToCon.idNode = temp_id;
			nodeToCon.ipNode = temp_ip;
			nodeToCon.portNode = temp_port;
			printf("Info Nodo CON RAREST-CHUNK-FIRST: %s, %s\n", nodeToCon.ipNode, nodeToCon.portNode);
			// Realizamos la conexion al par que tiene el chunk deseado.
			// ----------------------------------------------------------------------------------------------------------------
			// Lo relacionado al par que se desea conectar...
			// Iniciamos el socket por el cual el proceso cliente enviara y recibira mensajes...
		    int listener =  socket(AF_INET,SOCK_STREAM,0);
			if(listener == -1){
				printf("Error al abrir socket.\n");
				return; // Terminamos la ejecucion del programa.
			}
			struct sockaddr_in server;
			server.sin_addr.s_addr = inet_addr(nodeToCon.ipNode); // Aquí se pone la IP del par con el cual se desea comunicar.
			server.sin_family = AF_INET;
			server.sin_port = htons(atoi(nodeToCon.portNode)); // El puerto del par con el que se desea comunicar.
			// Iniciamos la conexion al servidor.
			int connect_TORARESTNODE = connect(listener, (struct sockaddr *)&server, sizeof(server));
			if(connect_TORARESTNODE < 0){
				perror("Imposible realizar conexion CON EL NODO RAREST-CHUNK-FIRST Error ");
				return; // Detenemos la descarga...
			}
			// -----------------------------------------------------------------------------------------------------------------
			//Una vez establecida la conexion enviamos el comando...
			// Enviamos el comando SENDME ...
			int send_ = writeSocket(listener, SEND_ME_COMAND, MAX_BUFF_COMMAND);
			if(send_ < 0){
				perror("Imposible enviar comando SENDME. Error ");
				return; 
			}
			// Esperamos el envio del tamaño del chunk...
			char chunkTam[MAX_BUFF_COMMAND];
			int rcv_ = readSocket(listener, chunkTam, MAX_BUFF_COMMAND);
			if(rcv_ < 0){
				perror("Imposible recibir el tamanio del chunk. Error ");
				return;
			}
			int TAM_CHUNK = atoi(chunkTam);
			// Esperamos el envio del chunk...
			char CHUNK_CONTENT_BUF[TAM_CHUNK]; // Cotenido del archivo.
			printf("Tamano chunk enviado:%s\n", chunkTam);
			
			rcv_ = readSocket(listener, CHUNK_CONTENT_BUF, TAM_CHUNK);

			char temp_chunkName[MAX_BUFF_COMMAND];
			sprintf(temp_chunkName, "%s", torrent.chunks[rarest_ok].idChunk);
			printf("NOMBRE TEMPORAL DE CHUNK: %s\n", temp_chunkName);
			writeFile(temp_chunkName, CHUNK_CONTENT_BUF, TAM_CHUNK);
			puts("Chunk recibido");
			close(listener);
			//Actualizamos la lista de chunks.
			char line[100];
			sprintf(line,"%s\t%s",torrent.chunks[rarest_ok].idChunk,torrent.chunks[rarest_ok].SHA);
			int lenLine = strlen(line);
			writeFile_("ChunkList.txt",line,lenLine);

			} // Cierra hilo...

		} // end while(1);
		puts("Descarga completa.");
		//Unimos los chunks recibidos.
		printf("TORRENT NAME: %s\n", fileName);
		char originalFileName[100];
		getName(fileName, strlen(fileName), originalFileName);
		printf("ORIGINAL NAME: %s\n", originalFileName);

		fileRebuilding(originalFileName, torrent.chunksQ);		
	}
	else if(validateEXIT(message_clientProcess)){
		// Matamos el proceso servidor...		
		// ----------------------------------------------------------------------------------------------------------------
		// Iniciamos el socket por el cual el proceso cliente enviara y recibira mensajes...
		int listener =  socket(AF_INET,SOCK_STREAM,0);
		if(listener == -1){
			printf("Error al abrir socket.\n");
			return; // Terminamos la ejecucion del programa.
		}
		// Lo relacionado al par que se desea conectar...
		struct sockaddr_in server;
		server.sin_addr.s_addr = htonl(INADDR_ANY); // Aquí se pone la IP del par con el cual se desea comunicar.
		server.sin_family = AF_INET;
		server.sin_port = htons(PORT); // El puerto del par con el que se desea comunicar.
		// Iniciamos la conexion al servidor.
		int connect_ = connect(listener, (struct sockaddr *)&server, sizeof(server));
		if(connect_ < 0){
			perror("Imposible realizar conexion. Error\n");
			return; // Detenemos la descarga...
		}
		int send_ = writeSocket(listener, "exit", MAX_BUFF_COMMAND);
		if(send_ < 0){
			perror("Imposible enviar comando EXIT. Error\n");
			return;
		}
		// -----------------------------------------------------------------------------------------------------------------
		close(listener);	
		exit(EXIT_SUCCESS);
		puts("CLIENTE FUERA.");
	}
	else{
		perror("COMANDO INVALIDO. Error ");
	}
	// Limpiamos buffers...
	fflush(stdout);
	fflush(stdin);	 
	memset(message_clientProcess, 0, sizeof(message_clientProcess));
	memset(message_clientProcess, 0, sizeof(message_clientProcess));
}


int writeSocket(int file_descriptor, char *buffer, int len) {
    int bytes_writed = 0;
    int aux = 0;
    if ((file_descriptor == -1) || (buffer == NULL) || (len < 1)){
        return -1;
    }
    while (bytes_writed < len) {
        aux = write(file_descriptor, buffer + bytes_writed, len - bytes_writed);
        if (aux > 0) {
            bytes_writed = bytes_writed + aux;
        } else {
            if (aux == 0) {
                printf("Bytes enviados: %d\n", bytes_writed);
                return bytes_writed;
            } else
                return -1;
        }
    }
    printf("Bytes enviados: %d\n", bytes_writed);
    return bytes_writed;
}

int readSocket(int file_descriptor, char *buffer, int len) {
    //int BUFMAX = 512*1024;
    int readed = 0;
    int aux = 0;    
    int i;
    for (i = 0; i < len; i++) {
        buffer[i] = '\0';
    }
    while (readed < len) {
        aux = read(file_descriptor, buffer + readed, len - readed);
        if (aux > 0) {
            readed = readed + aux;
        } else {
            if (aux == 0) {
                printf("Socket cerrado! Bytes recibidos: %d\n", aux);
                return readed;
            }
            if (aux == -1) {
                switch (errno) {
                    case EINTR:
                    case EAGAIN:
                        usleep(100);
                        break;
                    default:
                        return -1;
                }
            }
        }
    }
    printf("Bytes leidos: %d\n", readed);
    return readed;
}

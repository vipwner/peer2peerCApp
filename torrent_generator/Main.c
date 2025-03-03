// C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// CUSTOM LIBRARIES
#include "TorrentGenerator.h"
#include "View.h"

int main()
{
    char fileN[100];
    getData("Ingrese el pat del archivo: ", fileN);
    printf("Nombre del archivo en main(): %s\n", fileN);
    puts("Paso por linea 21 main()");
    puts("Paso por linea 23 main()");
    int ok = generateTorrent(fileN);
    if(ok == -1) {
        puts("No se pudo generar el torrent correctamente.");
    }
    puts("Paso por linea 25 main()");
    printf("%s\n", "Torrent generado con exito.");
    return 0;
}
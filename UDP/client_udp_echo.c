#include "udp.h"
#include "erreur.h"
#include "nombre.h"
#include "udp.c"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int traiter_commande_wrapper(int argc, char * argv){
	traiter_commande(argc,convertir_nombre( &argv[0]), "<adresse IP> <port> <message> <nb occurences>\nmauvais nombre d'arguments");
	traiter_commande(est_une_adresse_IP(argv[1]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
	traiter_commande(est_un_port_non_reserve(argv[2]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
	traiter_commande(est_un_entier_positif(argv[4]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");
}

int main(int argc, char* argv) {
	traiter_commande_wrapper(argc ,*argv);
	char adresse = argv[1];
	int occurence = argv[4];
	int port = argv[2];
	SOCK client;

	char* client_message = &argv[3];

	getw(client_message);
    
    // Send the message to server:
    if(sendto(socket_desc, client_message, strlen(client_message), 0,
         (struct sockaddr*)&server_addr, server_struct_length) < 0){
        printf("Unable to send message\n");
        return -1;
    }
    
    if(recvfrom(socket_desc, server_message, sizeof(server_message), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
	exit(0);
}

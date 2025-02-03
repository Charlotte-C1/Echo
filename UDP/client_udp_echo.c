#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int traiter_commande_wrapper(int argc, char **argv) {
    if (argc != 5) {
        traiter_commande(0, argv[0], "<adresse IP> <port> <message> <nb occurences>\nmauvais nombre d'arguments");
        return -1;
    }
    if (!est_une_adresse_IP(argv[1])) {
        traiter_commande(0, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
        return -1;
    }
    if (!est_un_port_non_reserve(argv[2])) {
        traiter_commande(0, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
        return -1;
    }
    if (!est_un_entier_positif(argv[4])) {
        traiter_commande(0, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");
        return -1;
    }
    return 0;
}


int main(int argc, char** argv) {
    if (traiter_commande_wrapper(argc,argv) !=0) {
        return -1;
    }
	char * adresse = (char *)argv[1];
	int occurence = (int)argv[4];
	int port = convertir_nombre(argv[2]);
	SOCK serveur;
	
  	char *client_message = argv[3];

	creer_socket();

	envoyer_message (*serveur, char * message);
    	recevoir_message(*serveur, char * buffer);
    
    if(recvfrom(socket_desc, server_message, sizeof(server_message), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
	
	fermer_connexion(client);
	exit(0);
}

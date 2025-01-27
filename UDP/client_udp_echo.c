#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int traiter_commande_wrapper(int argc, char ** argv){
	traiter_commande(argc, argv[0], "<adresse IP> <port> <message> <nb occurences>\nmauvais nombre d'arguments");
	traiter_commande(est_une_adresse_IP(argv[1]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
	traiter_commande(est_un_port_non_reserve(argv[2]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
	traiter_commande(est_un_entier_positif(argv[4]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");
}

int main(int argc, char** argv) {
	traiter_commande_wrapper(argc ,argv);


	exit(0);
}

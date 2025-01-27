#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
<<<<<<< HEAD
	//traiter_commande(/* A COMPLETER */, argv[0], "<adresse IP> <port> <message> <nb occurences>\nmauvais nombre d'arguments");
	//traiter_commande(/* A COMPLETER */, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
	//traiter_commande(/* A COMPLETER */, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
	//traiter_commande(/* A COMPLETER */, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");

	/*A COMPLETER*/

=======
	traiter_commande(argc, argv[0], "<adresse IP> <port> <message> <nb occurences>\nmauvais nombre d'arguments");
	traiter_commande(est_une_adresse_IP(argv[]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
	traiter_commande(est_un_port_non_reserve(argv[]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
	traiter_commande(est_un_entier_positif(argv[]), argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");
>>>>>>> e69f1ee32df5a9f113b035f679a74e71e5807dde
	exit(0);
}

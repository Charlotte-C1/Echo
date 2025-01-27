#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
<<<<<<< HEAD
	traiter_commande(argv.lenght, argv[0], "<port>\nmauvais nombre d'arguments");
	traiter_commande(/*A COMPLETER*/, argv[0], "<port>\n<port> est un port non réservé");

	/*A COMPLETER*/

=======
	traiter_commande(argc, argv[0], "<port>\nmauvais nombre d'arguments");
	traiter_commande(est_un_port_non_reserve(argv[1]), argv[0], "<port>\n<port> est un port non réservé");
>>>>>>> e69f1ee32df5a9f113b035f679a74e71e5807dde
	exit(0);
}

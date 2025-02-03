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

int main(int argc, char **argv) {
    if (traiter_commande_wrapper(argc, argv) != 0) {
        return -1;
    }

    int socket_desc;
    struct sockaddr_in server_addr;
    socklen_t server_struct_length = sizeof(server_addr);
    char server_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket_desc < 0) {
        printf("Unable to create socket\n");
        return -1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    char *client_message = argv[3];

    // Send the message to server
    if (sendto(socket_desc, client_message, strlen(client_message), 0,
               (struct sockaddr *)&server_addr, server_struct_length) < 0) {
        printf("Unable to send message\n");
        return -1;
    }

    // Receive the message from server
    if (recvfrom(socket_desc, server_message, sizeof(server_message), 0,
                 (struct sockaddr *)&server_addr, &server_struct_length) < 0) {
        printf("Error while receiving server's msg\n");
        return -1;
    }

    printf("Server response: %s\n", server_message);

    // Close the socket
    pclose(socket_desc);

    return 0;
}

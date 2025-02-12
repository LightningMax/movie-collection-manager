#include <stdio.h>
#include <string.h>
#include "cli_handler.h"

int lire_chaine(char* buffer, size_t taille, const char* message) {
    printf("%s", message);
    
    if (fgets(buffer, taille, stdin) == NULL) {
        return 0;
    }

    // Supprimer le retour à la ligne final
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }

    return 1;
}

int lire_entier(int min, int max, const char* message) {
    int valeur;
    char buffer[32];

    printf("%s", message);
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1;
    }

    if (sscanf(buffer, "%d", &valeur) != 1) {
        return -1;
    }

    if (valeur < min || valeur > max) {
        return -1;
    }

    return valeur;
}
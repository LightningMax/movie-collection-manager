#include <stdio.h>
#include <stdlib.h>
#include "cli_handler.h"
#include "list.h"

int main() {
    film_t* liste = NULL;
    
    printf("Bienvenue dans le gestionnaire d'utilisateurs!\n");
    boucle_principale(&liste);
    
    libererListe(&liste);
    printf("\nAu revoir!\n");
    
    return 0;
} 
#include <stdio.h>
#include "cli_handler.h"
#include "list.h"

void afficher_menu(void) {
    printf("\n%s=== GESTIONNAIRE DE FILMS ===%s\n", COLOR_BLUE, COLOR_RESET);
    printf("1. Ajouter un film\n");
    printf("2. Afficher les films\n");
    printf("3. Rechercher un film\n");
    printf("4. Supprimer un film\n");
    printf("5. Sauvegarder la liste\n");
    printf("0. Quitter\n\n");
}

void afficher_erreur_cli(const char* message) {
    printf("%s%s%s\n", COLOR_RED, message, COLOR_RESET);
}

void afficher_succes(const char* message) {
    printf("%s%s%s\n", COLOR_GREEN, message, COLOR_RESET);
}

int afficher_liste_paginee(const film_t* liste, int page) {
    int total = compterElements(liste);
    int nb_pages = (total + ITEMS_PAR_PAGE - 1) / ITEMS_PAR_PAGE;
    
    if (page < 1) page = 1;
    if (page > nb_pages) page = nb_pages;

    printf("\n%s=== LISTE DES FILMS (Page %d/%d) ===%s\n", 
           COLOR_BLUE, page, nb_pages, COLOR_RESET);
    printf("%-10s %-20s %-5s\n", "ID", "TITRE", "Note");
    printf("------------------------------------------------\n");

    const film_t* courant = liste;
    int i = 1;
    
    // Aller à la bonne page
    while (courant != NULL && i <= (page-1) * ITEMS_PAR_PAGE) {
        courant = courant->next;
        i++;
    }

    // Afficher les éléments de la page
    i = 0;
    while (courant != NULL && i < ITEMS_PAR_PAGE) {
        printf("%-10s %-20s %-5d\n",
               courant->id,
               courant->title,
               courant->note);
        courant = courant->next;
        i++;
    }

    return nb_pages;
} 
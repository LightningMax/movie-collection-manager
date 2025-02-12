#include <stdio.h>
#include "cli_handler.h"
#include "list.h"

void afficher_menu(void) {
    printf("\n%s=== GESTIONNAIRE DE FILMS ===%s\n", COLOR_BLUE, COLOR_RESET);
    printf("1. Ajouter un film\n");
    // printf("2. Ajouter des utilisateurs aléatoires\n");
    printf("3. Afficher les films\n");
    // printf("4. Rechercher un utilisateur\n");
    // printf("5. Modifier un utilisateur\n");
    // printf("6. Supprimer un utilisateur\n");
    printf("7. Sauvegarder la liste\n");
    // printf("8. Charger une liste\n");
    // printf("9. Aide\n");
    printf("0. Quitter\n\n");
}

// void afficher_aide(void) {
//     printf("\n%s=== AIDE ===%s\n", COLOR_YELLOW, COLOR_RESET);
//     printf("Ce programme permet de gérer une liste d'utilisateurs.\n");
//     printf("Vous pouvez :\n");
//     printf("- Ajouter des utilisateurs manuellement ou aléatoirement\n");
//     printf("- Afficher la liste avec pagination\n");
//     printf("- Rechercher par ID ou nom\n");
//     printf("- Modifier ou supprimer des utilisateurs\n");
//     printf("- Sauvegarder/charger la liste dans un fichier\n\n");
//     printf("Appuyez sur Entrée pour continuer...");
//     getchar();
// }

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
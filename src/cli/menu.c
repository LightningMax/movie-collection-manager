#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cli_handler.h>
#include "list.h"
#include "file_handler.h"

static void menu_ajouter(film_t** liste) {
    char title[50];
    int note;

    if (!lire_chaine(title, sizeof(title), "Titre: ")) return;
    note = lire_entier(1, 5, "Note: ");
    if (note == -1) return;

    film_error_t erreur = ajouterFilmDansListe(liste, title, note);
    if (erreur == FILM_SUCCESS) {
        afficher_succes("Film ajouté avec succès!");
    } else {
        afficher_erreur_cli("Erreur lors de l'ajout de le film!");
    }
}

static void menu_afficher(const film_t* liste) {
    int page = 1;
    int nb_pages;
    char buffer[3];  // Assez grand pour un caractère + \n + \0

    do {
        nb_pages = afficher_liste_paginee(liste, page);
        printf("\n(P)récédent, (S)uivant, (Q)uitter: ");
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return;
        }

        char choix = buffer[0];
        switch (choix) {
            case 'P':
            case 'p':
                if (page > 1) page--;
                break;
            case 'S':
            case 's':
                if (page < nb_pages) page++;
                break;
        }
    } while (buffer[0] != 'Q' && buffer[0] != 'q');
}

void boucle_principale(film_t** liste) {
    int choix;
    do {
        afficher_menu();
        choix = lire_entier(0, 9, "Votre choix: ");
        
        switch (choix) {
            case MENU_AJOUTER:
                menu_ajouter(liste);
                break;
            case MENU_SAUVEGARDER:
                sauvegarderListeFilms(*liste, "film_db.csv");
                break;
            // case MENU_AJOUTER_ALEATOIRE:
            //     menu_ajouter_aleatoire(liste);
            //     break;
            case MENU_AFFICHER:
                menu_afficher(*liste);
                break;
            // // ... autres cas à implémenter
            // case MENU_AIDE:
            //     afficher_aide();
            //     break;
        }
    } while (choix != MENU_QUITTER);
} 
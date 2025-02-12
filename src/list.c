#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "film.h"

// Fonction utilitaire locale pour générer un ID unique
static void genererID(char* id) {
    static int compteur = 1;
    snprintf(id, 10, "F%d", compteur++);
}

film_error_t ajouterFilmDansListe(film_t** liste, const char* title, int note) {
    if (liste == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    film_error_t erreur = validerInfosFilm(title, note);
    if (erreur != FILM_SUCCESS) {
        return erreur;
    }

    // Création du nouveau film
    film_t* nouvelFilm = malloc(sizeof(film_t));
    if (nouvelFilm == NULL) {
        return FILM_ERROR_MEMORY_ALLOCATION;
    }

    // Initialisation
    genererID(nouvelFilm->id);
    strncpy(nouvelFilm->title, title, 49);
    nouvelFilm->title[49] = '\0';
    nouvelFilm->note = note;
    nouvelFilm->next = *liste;

    *liste = nouvelFilm;
    return FILM_SUCCESS;
}
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

film_error_t trouverFilmDansListe(const film_t* liste, const char* title, film_t** resultat) {
    if (resultat == NULL || title == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    *resultat = NULL;
    const film_t* courant = liste;
    
    while (courant != NULL) {
        if (strcmp(courant->title, title) == 0) {
            *resultat = (film_t*)courant;
            return FILM_SUCCESS;
        }
        courant = courant->next;
    }

    return FILM_ERROR_NOT_FOUND;
}

film_error_t libererListe(film_t** liste) {
    if (liste == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    film_t* courant = *liste;
    while (courant != NULL) {
        film_t* suivant = courant->next;
        free(courant);
        courant = suivant;
    }

    *liste = NULL;
    return FILM_SUCCESS;
}

film_error_t supprimerUserDansListe(film_t** liste, const char* id) {
    if (liste == NULL || id == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    if (*liste == NULL) {
        return FILM_ERROR_NOT_FOUND;
    }

    film_t* courant = *liste;
    if (strcmp(courant->id, id) == 0) {
        *liste = courant->next;
        free(courant);
        return FILM_SUCCESS;
    }
}

int compterElements(const film_t* liste) {
    int compteur = 0;
    const film_t* courant = liste;
    
    while (courant != NULL) {
        compteur++;
        courant = courant->next;
    }
    
    return compteur;
} 
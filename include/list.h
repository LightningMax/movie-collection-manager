#ifndef LIST_H
#define LIST_H

#include "types.h"

/**
 * @brief Opérations sur la liste chaînée
 */
film_error_t ajouterFilmDansListe(film_t** liste, const char* title, int note);
film_error_t trouverFilmDansListe(const film_t* liste, const char* title, film_t** resultat);
// film_error_t supprimerFilmDansListe(film_t** liste, const char* id);
film_error_t libererListe(film_t** liste);
// film_error_t afficherListe(const film_t* liste);
int compterElements(const film_t* liste);

#endif // LIST_H 
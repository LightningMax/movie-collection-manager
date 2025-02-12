#ifndef LIST_H
#define LIST_H

#include "types.h"

/**
 * @brief Opérations sur la liste chaînée
 */
FilmError ajouterFilmDansListe(Film** liste, const char* title, int note);
FilmError trouverFilmDansListe(const Film* liste, const char* id, Film** resultat);
FilmError supprimerFilmDansListe(Film** liste, const char* id);
FilmError libererListe(Film** liste);
FilmError afficherListe(const Film* liste);
int compterElements(const Film* liste);

#endif // LIST_H 
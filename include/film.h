#ifndef FILM_H
#define FILM_H

#include "types.h"

/**
 * @brief Modifie les informations d'un film existant
 * @param film Film à modifier
 * @param title Nouveau tittre
 * @param note Nouvel note
 * @return Code d'erreur
 */
film_error_t modifierFilm(film_t* film, const char* title, int note);

/**
 * @brief Valide les informations d'un film
 * @param film Film à valider
 * @param title Titre à valider
 * @param note Note à valider
 * @return Code d'erreur
 */
film_error_t validerInfosFilm(const char* title, int note);

#endif // FILM_H 
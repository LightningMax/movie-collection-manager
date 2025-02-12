#include <string.h>
#include <assert.h>
#include "film.h"

film_error_t validerInfosFilm(const char* title, int note) {
    if (title == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    if (strlen(title) >= 50) {
        return FILM_ERROR_INVALID_PARAMETER;
    }

    if (note <= 0 || note > 5) {
        return FILM_ERROR_INVALID_PARAMETER;
    }

    return FILM_SUCCESS;
}

// UserError modifierUser(User* user, const char* lastname, const char* firstname, int age) {
//     // Vérification des paramètres
//     if (user == NULL) {
//         return USER_ERROR_NULL_POINTER;
//     }

//     UserError erreur = validerInfosUser(lastname, firstname, age);
//     if (erreur != USER_SUCCESS) {
//         return erreur;
//     }

//     // Modification des données
//     strncpy(user->lastname, lastname, 49);
//     user->lastname[49] = '\0';
//     strncpy(user->firstname, firstname, 49);
//     user->firstname[49] = '\0';
//     user->age = age;

//     return USER_SUCCESS;
// } 
#include <string.h>
#include <assert.h>
#include "film.h"

UserError validerInfosUser(const char* lastname, const char* firstname, int age) {
    if (lastname == NULL || firstname == NULL) {
        return USER_ERROR_NULL_POINTER;
    }

    if (strlen(lastname) >= 50 || strlen(firstname) >= 50) {
        return USER_ERROR_INVALID_PARAMETER;
    }

    if (age <= 0 || age > 150) {
        return USER_ERROR_INVALID_PARAMETER;
    }

    return USER_SUCCESS;
}

UserError modifierUser(User* user, const char* lastname, const char* firstname, int age) {
    // Vérification des paramètres
    if (user == NULL) {
        return USER_ERROR_NULL_POINTER;
    }

    UserError erreur = validerInfosUser(lastname, firstname, age);
    if (erreur != USER_SUCCESS) {
        return erreur;
    }

    // Modification des données
    strncpy(user->lastname, lastname, 49);
    user->lastname[49] = '\0';
    strncpy(user->firstname, firstname, 49);
    user->firstname[49] = '\0';
    user->age = age;

    return USER_SUCCESS;
} 
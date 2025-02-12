#ifndef CLI_MENU_H
#define CLI_MENU_H

#include "types.h"

typedef enum {
    MENU_QUITTER = 0,
    MENU_AJOUTER,
    MENU_AJOUTER_ALEATOIRE,
    MENU_AFFICHER,
    MENU_RECHERCHER,
    MENU_MODIFIER,
    MENU_SUPPRIMER,
    MENU_SAUVEGARDER,
    MENU_CHARGER,
    MENU_AIDE
} MenuChoice;

/**
 * @brief Lance la boucle principale du menu
 * @param liste Pointeur vers la liste de Films
 */
void boucle_principale(film_t** liste);

#endif // CLI_MENU_H 
#ifndef CLI_DISPLAY_H
#define CLI_DISPLAY_H

#include "types.h"

// Codes couleurs ANSI
#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"

#define ITEMS_PAR_PAGE 5

/**
 * @brief Affiche le menu principal
 */
void afficher_menu(void);

/**
 * @brief Affiche l'aide du programme
 */
void afficher_aide(void);

/**
 * @brief Affiche un message d'erreur en rouge
 * @param message Le message d'erreur
 */
void afficher_erreur_cli(const char* message);

/**
 * @brief Affiche un message de succès en vert
 * @param message Le message de succès
 */
void afficher_succes(const char* message);

/**
 * @brief Affiche une liste d'utilisateurs avec pagination
 * @param liste La liste à afficher
 * @param page La page courante
 * @return Le nombre total de pages
 */
int afficher_liste_paginee(const film_t* liste, int page);

#endif // CLI_DISPLAY_H 
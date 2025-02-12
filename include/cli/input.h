#ifndef CLI_INPUT_H
#define CLI_INPUT_H

#include <stddef.h>

/**
 * @brief Lit une chaîne de caractères de manière sécurisée
 * @param buffer Le buffer pour stocker la chaîne
 * @param taille La taille maximale du buffer
 * @param message Le message à afficher pour la saisie
 * @return 1 si succès, 0 si erreur
 */
int lire_chaine(char* buffer, size_t taille, const char* message);

/**
 * @brief Lit un entier avec validation
 * @param min Valeur minimum acceptée
 * @param max Valeur maximum acceptée
 * @param message Le message à afficher pour la saisie
 * @return L'entier lu ou -1 si erreur
 */
int lire_entier(int min, int max, const char* message);

/**
 * @brief Demande une confirmation à l'utilisateur (O/N)
 * @param message Le message de confirmation
 * @return 1 si confirmé, 0 sinon
 */
int confirmer_action(const char* message);

#endif // CLI_INPUT_H 
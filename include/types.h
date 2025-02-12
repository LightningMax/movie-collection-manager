#ifndef TYPES_H
#define TYPES_H

/**
 * @brief Codes d'erreur pour toutes les opérations
 */
typedef enum {
    FILM_SUCCESS = 0,            // Opération réussie
    FILM_ERROR_NULL_POINTER,     // Pointeur NULL passé en paramètre
    FILM_ERROR_MEMORY_ALLOCATION,// Échec d'allocation mémoire
    FILM_ERROR_INVALID_PARAMETER,// Paramètre invalide
    FILM_ERROR_NOT_FOUND,        // Film non trouvé
    FILM_ERROR_DUPLICATE_ID,     // ID déjà utilisé
    FILM_ERROR_FILE_OPEN,        // Impossible d'ouvrir le fichier
    FILM_ERROR_FILE_READ,        // Erreur de lecture fichier
    FILM_ERROR_FILE_WRITE,       // Erreur d'écriture fichier
    FILM_ERROR_FILE_FORMAT       // Format de fichier invalide
} film_error_t;

/**
 * @brief Structure représentant un Film
 */
typedef struct Film {
    char id[10];            // Identifiant unique
    char title[50];         // Nom de famille
    int note;               // Note
    struct Film* next;      // Pointeur vers l'Film suivant
} film_t;

#endif // TYPES_H 
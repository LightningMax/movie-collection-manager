#ifndef FILE_READER_H
#define FILE_READER_H

#include "../types.h"

/**
 * @brief Opérations de lecture de fichiers
 */
film_error_t chargerListeFilms(const char* filename, Film** liste);
film_error_t rechercherFilmDansFichier(const char* filename, const char* id, Film* user);

#endif // FILE_READER_H 
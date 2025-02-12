#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "../types.h"

/**
 * @brief Opérations d'écriture de fichiers
 */
film_error_t sauvegarderListeFilms(const film_t* liste, const char* filename);
film_error_t ajouterFilmFichier(const film_t* liste, const char* filename);

#endif // FILE_WRITER_H 
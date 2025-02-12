#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "../types.h"

/**
 * @brief Opérations d'écriture de fichiers
 */
FilmError sauvegarderListeFilms(const Film* liste, const char* filename);
FilmError ajouterFilmFichier(const Film* liste, const char* filename);

#endif // FILE_WRITER_H 
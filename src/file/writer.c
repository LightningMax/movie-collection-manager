#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"
#include "types.h"

film_error_t sauvegarderListeFilms(const film_t* liste, const char* filename) {
    if (filename == NULL) {
        return FILM_ERROR_NULL_POINTER;
    }

    // Mode "w" : crée un nouveau fichier vide ou écrase le contenu si le fichier existe déjà
    // C'est le comportement souhaité car on veut sauvegarder l'état complet de la liste
    FILE* fichier = fopen(filename, "w");
    if (fichier == NULL) {
        return FILM_ERROR_FILE_OPEN;
    }

    // Écriture de l'en-tête
    fprintf(fichier, "ID;TITRE;NOTE\n");

    // Écriture des utilisateurs
    const film_t* courant = liste;
    while (courant != NULL) {
        if (fprintf(fichier, "%s;%s;%d\n",
                   courant->id,
                   courant->title,
                   courant->note) < 0) {
            fclose(fichier);
            return FILM_ERROR_FILE_WRITE;
        }
        courant = courant->next;
    }

    fclose(fichier);
    return FILM_SUCCESS;
}
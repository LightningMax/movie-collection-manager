# Compilateur et options de base
CC = gcc
CFLAGS = -Wall -Wextra -I./include

# Support du mode debug
DEBUG ?= 0

# Dossiers
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Configuration selon le mode
ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 -DNDEBUG
endif

# Liste explicite des fichiers source
SOURCES = $(SRC_DIR)/list.c \
          $(SRC_DIR)/file/reader.c \
          $(SRC_DIR)/file/writer.c \
		  $(SRC_DIR)/cli/menu.c \
          $(SRC_DIR)/cli/display.c \
          $(SRC_DIR)/cli/input.c \
          main.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
TARGET = film_collection

# Règle principale
all: $(OBJ_DIR) $(TARGET)

# Création des dossiers obj s'ils n'existent pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/file

# Création de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation des fichiers source
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)
	rm -f *.txt *.json *.csv

# Pour éviter les conflits avec des fichiers qui pourraient s'appeler comme nos règles
.PHONY: all clean 
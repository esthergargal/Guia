# Esther García Gallego
# INGENIERÍA INFORMÁTICA 2ºB
# Práctica 4 ED - Guia telefónica


# Carpeta donde se guardan los ejecutables
BIN = ./bin
# Compilador
CC = g++
# Carpeta donde se guarda la documentación
DOC = ./doc
# Carpeta donde se guardan los .h
INCLUDE = ./include
# Carpeta donde se guardan los objetos
OBJ = ./obj
# Carpeta donde se guardan los .cpp
SRC = ./src
# Navegador
BROWSER = firefox

guia: $(OBJ)/guiatlf.o
	$(CC) -o $(BIN)/guia -I$(INCLUDE) $(SRC)/testguia.cpp $(OBJ)/guiatlf.o

$(OBJ)/guiatlf.o:
	$(CC) -c $(SRC)/guiatlf.cpp -I$(INCLUDE) -o $(OBJ)/guiatlf.o

clean:
	@echo "Limpiando..."
	rm -f $(OBJ)/* $(BIN)/*

doxy:
	@echo "Creando documentación..."
	@echo
	@echo
	doxygen Doxyfile

display_doxy:
	@echo "Mostrando documentación..."
	@echo
	@echo
	$(BROWSER) $(DOC)/html/index.html &

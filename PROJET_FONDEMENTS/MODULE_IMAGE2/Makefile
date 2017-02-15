CC=gcc
CFLAG=-Wall -g
LIBS=-L/home/public/PROJET_FONDEMENTS/MODULE_IMAGE/
OBJ=main.o image.o image_util.o quadtree.o
OUTPUT=testimage

$(OUTPUT): $(OBJ)
	$(CC) $(OBJ) -o $@ libimage64.a 

clean:
	rm -f $(OUTPUT) $(OBJ)

main.o: main.c image.h objet.h exit_if.h classe.h point.h move_type.h \
  type_obj.h image_util.h quadtree.h
	$(CC) $(CFLAG) -c main.c

CC = gcc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
FLAGGLUT=-lglut -lGL -lGLU
endif
ifeq ($(UNAME_S),Darwin)
FLAGGLUT=-Wno-deprecated-declarations -framework OpenGL -framework GLUT
endif

FLAG=-Wall -std=c99
EXEC = Wing2Wing
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)
	clear
	./$(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(FLAG) $(FLAGGLUT)

%.o : %.c
	$(CC) -o $@ -c $< $(FLAG) $(FLAGGLUT)

clean :
	rm -rf *o
	rm -rf $(EXEC)

zip :
	zip fichier.zip *.*
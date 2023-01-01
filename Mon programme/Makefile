# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = -lX11
LIBSDIR = 

# fichiers du projet
SRC = clientAPI.c labyrinthAPI.c main.c structure.c
# mainP2.c score.c 
#individu.c mainP1.c 
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
clientAPI.o: clientAPI.h clientAPI.c
labyrinthAPI.o: labyrinthAPI.h labyrinthAPI.c
structure.o: structure.h structure.c

# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o

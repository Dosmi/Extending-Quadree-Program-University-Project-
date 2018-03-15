
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree

SRC= main.c writeTree.c buildTree.c tests.c valueTree.c

# generic build details

CC=      cc
COPT=    -g
LIBS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

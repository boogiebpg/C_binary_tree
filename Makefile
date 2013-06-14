CC           = gcc
FLAGS        = # -std=gnu99 -Iinclude
CFLAGS       = -fPIC -g #-pedantic -Wall -Wextra -ggdb3
LDFLAGS      = -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

BINARY_TREE  = binary_tree
SHARED_LIB   = binary_tree.so
STATIC_LIB   = binary_tree.a
SOURCES      = binary_tree.c binary_tree_test.c
HEADERS      = binary_tree.h
OBJECTS      = $(SOURCES:.c=.o)

all: $(SHARED_LIB) $(STATIC_LIB) $(BINARY_TREE)

$(SHARED_LIB): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $(LDFLAGS) $(DEBUGFLAGS) -o $(SHARED_LIB) $(OBJECTS)

$(STATIC_LIB): $(OBJECTS)
	ar -cvq $(STATIC_LIB) $(OBJECTS)

$(BINARY_TREE):  $(OBJECTS) $(STATIC_LIB)
	$(CC) -o $(BINARY_TREE) $(OBJECTS) $(STATIC_LIB)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(SHARED_LIB)
	$(RM) $(STATIC_LIB)
	$(RM) $(BINARY_TREE)

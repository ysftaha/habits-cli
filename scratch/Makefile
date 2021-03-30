# habits command line interface
# See LICENSE file for copyright and license details.
ifndef VERBOSE
.SILENT:
endif

VERSION  = 0.1
CFLAGS   = -std=c17 -pedantic -Wall -Os $(INCS)
CC       = clang

# PREFIX = ${HOME}/.local
# MANPREFIX = $(PREFIX)/share/man
# INCS = -I$(X11INC) -I$(FREETYPEINC)
LIBS = -lm

SRC = scratch.c
OBJ = $(SRC:.c=.o)

all: scratch run

options:
	@echo habits-cli build options
	@echo "        [flags]     CFLAGS = $(CFLAGS)"
	@echo "        [Includes]  INCS   = $(INCS)"
	@echo "        [Libraries] LIBS   = $(LIBS)"
	@echo "        [compiler]  CC     = $(CC)"

scratch: scratch.o
	$(CC) -o $@ scratch.o $(LIBS)

run: scratch
	./scratch -d 12/12/20 -f f1 -f f2 -f f3 -f f4

$(OBJ):

.c.o:
	$(CC) -c $(CFLAGS) $<

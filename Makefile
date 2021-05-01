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

SRC = hbtcli.c hbtlib.c
OBJ = $(SRC:.c=.o)

all: hbtcli runcli

options:
	@echo habits-cli build options
	@echo "        [flags]     CFLAGS = $(CFLAGS)"
	@echo "        [Includes]  INCS   = $(INCS)"
	@echo "        [Libraries] LIBS   = $(LIBS)"
	@echo "        [compiler]  CC     = $(CC)"

.c.o:
	$(CC) -c $(CFLAGS) $<

$(OBJ): hbtlib.h

hbtcli: hbtcli.o hbtlib.o
	$(CC) -o $@ hbtcli.o hbtlib.o $(LIBS)

runcli: hbtcli
	./hbtcli -f

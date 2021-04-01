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

SRC = hcli.c
OBJ = $(SRC:.c=.o)

all: hcli run

options:
	@echo habits-cli build options
	@echo "        [flags]     CFLAGS = $(CFLAGS)"
	@echo "        [Includes]  INCS   = $(INCS)"
	@echo "        [Libraries] LIBS   = $(LIBS)"
	@echo "        [compiler]  CC     = $(CC)"

hcli: hcli.o
	$(CC) -o $@ hcli.o $(LIBS)

run: hcli
	./hcli -h

$(OBJ):

.c.o:
	$(CC) -c $(CFLAGS) $<

# Habits-cli
TODO: Intro

# Building
TODO: A Makefile


## Prerequisites
- C11 
- Sqlite3, check the C api is installed `#include <sqlite3.h>`
- TODO: Go front end using one (or more?) of:
	- [termui](https://github.com/gizak/termui)
	- [termdash](https://github.com/mum4k/termdash)
	- [tview](https://github.com/rivo/tview)
	- [gowid](https://github.com/gcla/gowid)
> there is also tui-rs but that is built in Rust.

# Directory
```txt
.
├── hbtcli.c		# cli front end
├── hbtlib.c	  # sqlite interface
├── hbtlib.h 		# header for hbtlib.c
├── LICENSE
├── Makefile
└── README.md
```

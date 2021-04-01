/**
 * @file hcli.c
 * @brief Adds, removes, and edits habits in the sqlite3 database
 */
#include <getopt.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Typedefs/Structs */
typedef struct tm tm;

typedef union recur {
  bool frequency[7]; // Days of week
  size_t repeat;
} recur;

typedef struct habit {
  const char *name;
  recur rec;
  tm start_date;
} habit;

/* Globals */

/* Prototypes */
void add(const char *habit_name);
void rem(const char *habit_name);
void usage();

void add(const char *habit_name) {}
void rem(const char *habit_name) {}
void usage() {
  puts("Usage: hcli -a habit_name < -d dd/mm/yy -R repeat | -F frequency_list > | -r "
       "habit_name");
}

int main(int argc, char *argv[]) {
  char opt;
	// @TODO still needs work
  while ((opt = getopt(argc, argv, ":a:r:f:")) != -1) {
    switch (opt) {
    case 'h':
      usage();
      break;
    case 'a':
      add(optarg);
      break;
    case 'r':
      rem(optarg);
      break;
    default:
      usage();
      fprintf(stderr, "[Err] Not enough arguments\n");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}

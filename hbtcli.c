/**
 * @file hcli.c
 * @brief Adds, removes, and edits habits in the sqlite3 database
 */
#include "hbtlib.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void usage();
void version();
/** @todo */
habit create(const char *hbt_name, const bool is_freq, const char *rec,
             const char *date);

void usage() {
  puts("Usage: hcli (-a | -d) habit -s DD/MM/YY (-r <num> | -f <0-6>)\n"
       "       hcli -v\n" // version
       "       hcli -h\n" // help
       "       hcli -l\n" // list habits in db
       "Options:\n"
       "    -v               Show version.\n"
       "    -h               This help message and usage.\n"
       "    -l               List habit names in database and general info.\n"
       "    -a <habit-name>  Add a habit.\n"
       "    -s <DD/MM/YY>    Set starting date (inclusive) of tracking habit\n"
       "                     when adding a habit.\n"
       "    -r <num>         Set repeatition when adding a habit.\n"
       "                     Example: hcli -a habit-name -r 7 -s DD/MM/YY.\n"
       "                     Note: '-r' and '-f' are mutually exclusive.\n"
       "    -f <0-6>         Set frequency when adding a habit. Where 0 is\n"
       "                     the starting day of the week.\n"
       "                     Example: hcli -a habit-name -f 013 -s DD/MM/YY.\n"
       "                              This adds a habit that repeats every\n"
       "                              Monday(0), Tuesday(1), Thursday(3).\n"
       "                     Note: '-r' and '-f' are mutually exclusive.\n"
       "    -d <name>        Delete a habit 'name' if it exists.\n");
}

/**
 * @brief prints the current verion of hcli.
 */
void version() { puts("hcli pre-alpha"); }

int main(int argc, char *argv[]) {
  char opt;
  if (argc == 1) {
    puts("[Err] Not enough arguments");
    usage();
  }
  while ((opt = getopt(argc, argv, ":hv")) != -1) {
    switch (opt) {
    case 'v':
      version();
      break;
    case 'h':
      usage();
      break;
    case '?':
    default:
      puts("[Err] Unrecognized argument");
      usage();
      break;
    }
  }
}

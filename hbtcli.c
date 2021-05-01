/**
 * @file hcli.c
 * @brief Adds, removes, and edits habits in the sqlite3 database
 */
#include "hbtlib.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage();
void version();
habit create(char *args[4]);
void del(char *name);

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
       "                     Note: '-s' must come after '-a'\n"
       "                     when adding a habit.\n"
       "    -r <num>         Set repeatition when adding a habit.\n"
       "                     Example: hcli -a habit-name -r 7 -s DD/MM/YY.\n"
       "                     Note: '-r' and '-f' are mutually exclusive,\n"
       "                           and must come after '-a'.\n"
       "    -f <0-6>         Set frequency when adding a habit. Where 0 is\n"
       "                     the starting day of the week.\n"
       "                     Example: hcli -a habit-name -f 013 -s DD/MM/YY.\n"
       "                              This adds a habit that repeats every\n"
       "                              Monday(0), Tuesday(1), Thursday(3).\n"
       "                     Note: '-r' and '-f' are mutually exclusive,\n"
       "                           and must come after '-a'.\n"
       "    -d <name>        Delete a habit 'name' if it exists. If multiple\n"
       "                     names are given, only the first will be deleted");
}

/**
 * @brief prints the current verion of hcli.
 */
void version() { puts("hcli pre-alpha"); }

int main(int argc, char *argv[]) {
  char opt;
  char *add_args[4]; /** [ a , s , f , r ] */
  size_t add_arg_num = 0;

  for (int i = 0; i < 4; ++i)
    add_args[i] = "";

  if (argc == 1) {
    puts("[Err] Not enough arguments");
    usage();
  }

  while ((opt = getopt(argc, argv, ":hva:f:r:s:d:")) != -1) {
    switch (opt) {
    case 'a':
      if (strcmp(add_args[0], "")) {
        printf("[Err] Multiple -%c flags.\n", opt);
        exit(EXIT_FAILURE);
      }
      add_args[0] = optarg;
      ++add_arg_num;
      break;
    case 'f':
      if (strcmp(add_args[1], "")) {
        printf("[Err] Multiple -%c flags.\n", opt);
        exit(EXIT_FAILURE);
      }
      if (strcmp(add_args[2], "")) {
        puts("[Err] -f and -r are mutually exclusive.");
        exit(EXIT_FAILURE);
      }
      add_args[1] = optarg;
      ++add_arg_num;
      break;
    case 'r':
      if (strcmp(add_args[2], "")) {
        printf("[Err] Multiple -%c flags.\n", opt);
        exit(EXIT_FAILURE);
      }
      if (strcmp(add_args[1], "")) {
        puts("[Err] -f and -r are mutually exclusive.");
        exit(EXIT_FAILURE);
      }
      add_args[2] = optarg;
      ++add_arg_num;
      break;
    case 's':
      if (strcmp(add_args[3], "")) {
        printf("[Err] Multiple -%c flags.\n", opt);
        exit(EXIT_FAILURE);
      }
      add_args[3] = optarg;
      ++add_arg_num;
      break;
    case 'd':
      del(optarg);
      break;
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

  if (add_arg_num == 3)
    create(add_args);

  return 0;
}

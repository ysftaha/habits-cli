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
  puts("Usage: hcli (-a | -r) habit -d dd/mm/yy (-R repeat | -F "
       "frequency_list)\n"
       "       hcli -l\n" // list habits in db
       "       hcli -v\n" // version
       "       hcli -h\n" // help
       "Options:\n");
}

void version() {}

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

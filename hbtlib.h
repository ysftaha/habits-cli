/**
 * @file hbtlib.h
 * @brief To decouple the databse driver from the cli/tui and possibly a gui
 * front end, all databse functions go through this header and are implemented
 * int he hbtlib.c source file.
 * @see hbtlib.c
 */
#ifndef HBT_CON
#define HBT_CON

#include <sqlite3.h>
#include <stdbool.h>
#include <sys/types.h>
#include <time.h>

/**
 * @brief holds time and date
 */
typedef struct tm tm;

/**
 * @brief creates a typedef for recur
 * @union recur containing either frequency or repeatition info
 */
typedef union recur {
  bool frequency[7]; // Days of week
  size_t repeat;  	 // Every x days
} recur;

typedef struct habit {
  const char *name;
	const size_t perday; /** times per day */
  recur rec;
  tm start_date;
} habit;

extern bool exists(habit *hbt);
extern bool add(habit *hbt);
extern bool rem(habit *hbt);

#endif

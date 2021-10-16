/**
 * test-rms.c
 * A quick test of recursive merge sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "austin-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (austin_sort);
  return errors;
} // main

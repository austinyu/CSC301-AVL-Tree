/**
 * austin-sort.c
 * An implementation of austin sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+
#include <strings.h>
#include "austin-sort.h"
#include "strutils.h"
#include "insertion-sort.h"

#define SIZE 8
// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+
void
aSort_kernel (char *strings[], int len, char *scratch[])
{
  if (len < SIZE)
    {
      // do insertion sort when the size of the array is small enough
      insertion_sort(strings, len);
      return;
    }
  // Recursive case: Split into two halves, sort the halves, merge
  int halfsize = len/2;
  aSort_kernel (strings, halfsize, scratch);
  aSort_kernel (strings+halfsize, len-halfsize, scratch);
  merge (strings, 0, halfsize, len, scratch);
} // kernel

void
austin_sort (char *strings[], int len)
{
  // Allocate a scratch array
  char *scratch[len];

  // Use the kernel
  aSort_kernel (strings, len, scratch);
} // recursive-merge_sort


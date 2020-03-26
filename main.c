#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#include "./lib/_heap.h"

int main(int argc, char const *argv[])
{
  int arr[] = {12, 13, 14, 20};

  // make
  heap_t *heap;
  heap = make_max_heap(arr, 4);
  _print(heap);

  // insert
  int value = 60;
  heap_insert(heap, value);
  _print(heap);

  value = 50;
  heap_insert(heap, value);
  _print(heap);

  value = 1;
  heap_insert(heap, value);
  _print(heap);

  // remove
  heap_remove(heap); // 60
  _print(heap);
  heap_remove(heap); // 50
  _print(heap);
  heap_remove(heap); // 20
  _print(heap);

  return 0;
}

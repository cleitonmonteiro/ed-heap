#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#include "./lib/_heap.h"

int main(int argc, char const *argv[])
{
  int arr[] = {12, 13, 14, 20};

  printf("\n =============== HEAP MAX\n");
  // make
  heap_t *heap;
  heap = heap_make_max(arr, 4);
  _print(heap);

  // insert
  int value = 60;
  heap_insert_max(heap, value);
  _print(heap);

  value = 50;
  heap_insert_max(heap, value);
  _print(heap);

  value = 1;
  heap_insert_max(heap, value);
  _print(heap);

  // remove
  heap_remove_max(heap); // 60
  _print(heap);
  heap_remove_max(heap); // 50
  _print(heap);
  heap_remove_max(heap); // 20
  _print(heap);

  printf(" =============== HEAP MIN\n");

  // make
  heap = heap_make_min(arr, 4);
  _print(heap);

  // insert
  value = 60;
  heap_insert_min(heap, value);
  _print(heap);

  value = 50;
  heap_insert_min(heap, value);
  _print(heap);

  value = 1;
  heap_insert_min(heap, value);
  _print(heap);

  // remove
  heap_remove_min(heap); // 1
  _print(heap);
  heap_remove_min(heap); // 12
  _print(heap);
  heap_remove_min(heap); // 13
  _print(heap);
  return 0;
}

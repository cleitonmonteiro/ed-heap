#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#include "./lib/_heap.h"

int main(int argc, char const *argv[])
{
  int arr[] = {12, 13, 14, 20};

  printf("\n:::::::::::::::::::::: HEAP MAX ::::::::::::::::::::::\n");
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

  heap_sort_max(heap->arr, heap->length);
  _print(heap);

  int arr_max[] = {122, 103, 14, 10, 900, 1, 89};
  heap_sort_max(arr_max, 7); //  [ 1 10 14 89 103 122 900 ]


  printf(":::::::::::::::::::::: HEAP MIN ::::::::::::::::::::::\n");

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

  int arr_min[] = {122, 103, 14, 10, 900, 1, 89};
  heap_sort_min(arr_min, 7); // [ 900 122 103 89 14 10 1 ]

  return 0;
}

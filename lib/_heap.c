#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include "_heap.h"

void _print_arr(int *arr, int start, int size)
{
  printf("[ ");
  for (int c = start; c < start + size; c++)
  {
    printf("%i ", arr[c]);
  }
  printf("]\n");
}

void _print(heap_t *heap)
{
  printf("\nHeap: {\n");
  printf(" capacity : %i\n", heap->capacity);
  printf(" length   : %i\n", heap->length);
  printf(" arr      : ");
  _print_arr(heap->arr, 1, heap->length);
  printf("\n");

  int arr_index;
  int num_lines = (int)floor(log2(heap->length) + 1);

  for (int line = 1; line <= num_lines; line++)
  {
    int num_vertices_line = (int)pow(2, line - 1);
    int previous_num_vertices = (int)pow(2, line - 1) - 1;
    // DEBUG:
    // printf("nvl: %i  pnv: %i\n", num_vertices_line, previous_num_vertices);
    for (int vertice = 1; vertice <= num_vertices_line; vertice++)
    {
      arr_index = previous_num_vertices + vertice;
      if (arr_index <= heap->length)
      {
        printf(" %i ", heap->arr[arr_index]);
      }
    }
    printf("\n");
  }
  printf("}\n\n");
}

void _swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void _copy(int *source, int *destiny, int size)
{
  for (int c = 1; c <= size; c++)
  {
    destiny[c] = source[c - 1];
  }
}

int is_full(heap_t *heap)
{
  if (heap->length == heap->capacity)
    return 1;
  return 0;
}

int is_empty(heap_t *heap)
{
  if (heap->length == 0)
    return 1;
  return 0;
}

void heap_down_max(heap_t *heap, int position)
{
  int child = 2 * position;
  if (child <= heap->length)
  {
    if (child < heap->length)
    {
      if (heap->arr[child + 1] > heap->arr[child])
      {
        child = child + 1;
      }
    }
    if (heap->arr[position] < heap->arr[child])
    {
      _swap(heap->arr, position, child);
      heap_down_max(heap, child);
    }
  }
}

void heap_up_max(heap_t *heap, int position)
{
  int father = (int)floor(position / 2);
  if (father >= 1)
  {
    if (heap->arr[position] > heap->arr[father])
    {
      _swap(heap->arr, position, father);
      heap_up_max(heap, father);
    }
  }
}

void heap_insert(heap_t *heap, int new_value)
{
  if (!is_full(heap))
  {
    // LOG:
    printf("LOG: inserted(%i)\n", new_value);
    heap->length++;
    heap->arr[heap->length] = new_value;
    heap_up_max(heap, heap->length);
  }
  else
  {
    // LOG: Underflow
    printf("LOG: Overflow: insert(%i)\n", new_value);
  }
  // FAILURE: Overflow
}

int heap_remove(heap_t *heap)
{
  if (!is_empty(heap))
  {
    int temp = heap->arr[1];

    heap->arr[1] = heap->arr[heap->length];
    heap->length--;
    heap_down_max(heap, 1);

    // LOG:
    printf("LOG: removed(%i)\n", temp);

    return temp;
  }
  // LOG: Underflow
  printf("LOG: Underflow: remove()\n");
  return INT_MIN;
}

heap_t *make_max_heap(int *arr, int size)
{
  heap_t *heap;
  heap = (heap_t *)calloc(1, sizeof(heap_t));
  heap->length = size;
  heap->capacity = MAX_CAPACITY;
  heap->arr = (int *)calloc(heap->capacity, sizeof(int));
  _copy(arr, heap->arr, size);

  int position = (int)floor(heap->length / 2);

  for (; position >= 1; position--)
  {
    heap_down_max(heap, position);
  }
  return heap;
}

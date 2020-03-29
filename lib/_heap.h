#ifndef _HEAP_H_
#define _HEAP_H_

#define MAX_CAPACITY 100

typedef struct
{
  int *arr;
  int length;
  int capacity;
} heap_t;

void _print_arr(int *arr, int start, int size);
void _print(heap_t *heap);
void _swap(int *arr, int i, int j);
void _copy(int *source, int *destiny, int size);
int is_full(heap_t *heap);
int is_empty(heap_t *heap);

void heap_down_max(heap_t *heap, int position);
void heap_up_max(heap_t *heap, int position);
void heap_insert_max(heap_t *heap, int new_value);
int heap_remove_max(heap_t *heap);
heap_t *heap_make_max(int arr[], int size);

void heap_down_min(heap_t *heap, int position);
void heap_up_min(heap_t *heap, int position);
void heap_insert_min(heap_t *heap, int new_value);
int heap_remove_min(heap_t *heap);
heap_t *heap_make_min(int arr[], int size);


#endif

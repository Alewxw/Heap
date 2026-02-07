#ifndef _heapu_
#define _heapu_
#define MAX_HEAP_SIZE 100

typedef struct hip{
    int arr[MAX_HEAP_SIZE];
    int heap_size; // numarul curent de elemente
    int length; // capacitatea
}Heap;

int parent ( int index );
int leftChild ( int index );
int rightChild ( int index );

void heap_init ( Heap *h );

void max_heapify ( Heap *h, int index );

void build_MaxHeap ( Heap *h );

void heap_sort ( Heap *h );

int heap_max ( Heap *h );

int heap_extractmax ( Heap *h );

void heap_increaseKey ( Heap *h, int index, int key );

void max_heap_insert ( Heap *h, int key );

void heap_print ( Heap *h );


#endif // _heapu_

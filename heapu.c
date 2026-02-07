#include <stdlib.h>
#include <stdio.h>
#include "heapu.h"
#include <limits.h>

int parent ( int index )
{
    return (index - 1 )/ 2;
}

int leftChild ( int index )
{
    return 2 * index + 1;
}

int rightChild ( int index )
{
    return 2 * index + 2;
}

void heap_init ( Heap *h )
{
    h->heap_size = 0;
    h->length = MAX_HEAP_SIZE;
}

void max_heapify ( Heap *h, int index )
{
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if ( left < h->heap_size && h->arr[left] > h->arr[largest] ) largest = left;

    if ( right < h->heap_size && h->arr[right] > h->arr[largest] ) largest = right;

    if ( largest != index )
    {
        int aux = h->arr[index];
        h->arr[index] = h->arr[largest];
        h->arr[largest] = aux;

        max_heapify(h, largest);

    }
}

void build_MaxHeap ( Heap *h )
{
    for ( int i = h->heap_size / 2 - 1 ; i >= 0 ; i -- )
        max_heapify(h, i);
}

int heap_max ( Heap *h )
{
    return h->arr[0];
}

int heap_extractmax ( Heap *h )
{
    if ( h->heap_size < 1 )
    {
        printf("Heap-ul e gol\n");
        return INT_MIN;
    }

    int x = heap_max(h);
    h->arr[0] = h->arr[h->heap_size-1];
    h->heap_size--;
    max_heapify(h, 0);

    return x;
}

void heap_increaseKey ( Heap *h, int index, int key )
{
    if ( h->arr[index] > key )
    {
        printf("Noua cheie este mai mica decat cea curenta\n");
        return ;
    }

    h->arr[index] = key;

    while ( index > 0 && h->arr[parent(index)] < h->arr[index] )
    {
        int aux = h->arr[parent(index)];
        h->arr[parent(index)] = h->arr[index];
        h->arr[index] = aux;

        index = parent(index);
    }
}

void heap_sort ( Heap *h )
{
    build_MaxHeap(h);

    int originalSize = h->heap_size;
    for ( int i = h->heap_size - 1 ; i >= 0 ; i -- )
    {
        int aux = h->arr[0];
        h->arr[0] = h->arr[i];
        h->arr[i] = aux;

        h->heap_size--;
        max_heapify(h, 0);
    }

    h->heap_size = originalSize;
}

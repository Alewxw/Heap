#include <stdio.h>
#include <stdlib.h>
#include "heapu.h"
#include <limits.h>

void print_menu()
{
    printf("\n===== MENIU HEAP MAX =====\n");
    printf("1. Initializare heap\n");
    printf("2. Inserare element\n");
    printf("3. Afisare maxim\n");
    printf("4. Extragere maxim\n");
    printf("5. Crestere cheie\n");
    printf("6. Heap sort\n");
    printf("7. Afisare heap\n");
    printf("0. Iesire\n");
    printf("Alege o optiune: ");
}

int main()
{
    Heap h;
    int opt;
    int x, index, key;

    heap_init(&h);

    do
    {
        print_menu();
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            heap_init(&h);
            printf("Heap initializat.\n");
            break;

        case 2:
            if (h.heap_size >= h.length)
            {
                printf("Heap-ul este plin!\n");
                break;
            }

            printf("Introdu valoarea: ");
            scanf("%d", &x);

            h.arr[h.heap_size] = INT_MIN;
            h.heap_size++;
            heap_increaseKey(&h, h.heap_size - 1, x);

            printf("Element inserat.\n");
            break;

        case 3:
            if (h.heap_size > 0)
                printf("Maximul este: %d\n", heap_max(&h));
            else
                printf("Heap-ul este gol.\n");
            break;

        case 4:
            x = heap_extractmax(&h);
            if (x != INT_MIN)
                printf("Maxim extras: %d\n", x);
            break;

        case 5:
            printf("Index: ");
            scanf("%d", &index);

            if (index < 0 || index >= h.heap_size)
            {
                printf("Index invalid!\n");
                break;
            }

            printf("Noua cheie: ");
            scanf("%d", &key);

            heap_increaseKey(&h, index, key);
            break;

        case 6:
            heap_sort(&h);
            printf("Heap sort efectuat.\n");
            break;

        case 7:
            if (h.heap_size == 0)
            {
                printf("Heap-ul este gol.\n");
                break;
            }

            printf("Heap: ");
            for (int i = 0; i < h.heap_size; i++)
                printf("%d ", h.arr[i]);
            printf("\n");
            break;

        case 0:
            printf("La revedere 👋\n");
            break;

        default:
            printf("Optiune invalida!\n");
        }

    } while (opt != 0);

    return 0;
}

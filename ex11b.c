#include <stdio.h>
#include <limits.h>

void insert(int ary[], int hFn, int size)
{
    int element, pos, n = 0;

    printf("Enter key element to insert: ");
    scanf("%d", &element);

    pos = element % hFn;

    while (n < size) {
        if (ary[pos] == INT_MIN || ary[pos] == INT_MAX) {
            ary[pos] = element;
            printf("Element inserted\n");
            return;
        }

        pos = (pos + 1) % hFn;
        n++;
    }

    printf("Hash table is full. No place to insert this element.\n");
}

void delete(int ary[], int hFn, int size)
{
    int element, pos, n = 0;

    printf("Enter element to delete: ");
    scanf("%d", &element);

    pos = element % hFn;

    while (n < size) {
        if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        }

        if (ary[pos] == element) {
            ary[pos] = INT_MAX;
            printf("Element deleted\n");
            return;
        }

        pos = (pos + 1) % hFn;
        n++;
    }

    printf("Element not found in hash table\n");
}

void search(int ary[], int hFn, int size)
{
    int element, pos, n = 0;

    printf("Enter element you want to search: ");
    scanf("%d", &element);

    pos = element % hFn;

    while (n < size) {
        if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        }

        if (ary[pos] == element) {
            printf("Element found at index %d\n", pos);
            return;
        }

        pos = (pos + 1) % hFn;
        n++;
    }

    printf("Element not found in hash table\n");
}

void display(int ary[], int size)
{
    printf("\nIndex\tValue\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t", i);

        if (ary[i] == INT_MIN) {
            printf("Empty\n");
        } else if (ary[i] == INT_MAX) {
            printf("Deleted\n");
        } else {
            printf("%d\n", ary[i]);
        }
    }
}

int main()
{
    int size, hFn, choice;

    printf("Enter size of hash table: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int ary[size];

    printf("Enter hash function (mod value): ");
    scanf("%d", &hFn);

    if (hFn <= 0 || hFn > size) {
        printf("Invalid hash function\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        ary[i] = INT_MIN;
    }

    do {
        printf("\nEnter your choice\n");
        printf("1 -> Insert\n");
        printf("2 -> Delete\n");
        printf("3 -> Display\n");
        printf("4 -> Search\n");
        printf("0 -> Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(ary, hFn, size);
                break;

            case 2:
                delete(ary, hFn, size);
                break;

            case 3:
                display(ary, size);
                break;

            case 4:
                search(ary, hFn, size);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter correct choice\n");
        }
    } while (choice != 0);

    return 0;
}
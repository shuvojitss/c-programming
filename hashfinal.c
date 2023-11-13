#include <stdio.h>
#include <stdlib.h>
int *hash, key, flag, i, found;
int size; 
void insert(int item) {
    int f = 0;
    key = (item % size) - 1;
    if (hash[key] == -1)
        hash[key] = item;
    else {
        if (key < size - 1) {
            for (i = key + 1; i < size; i++) {
                if (hash[i] == -1) {
                    hash[i] = item;
                    f = 1;
                    break;
                }
            }
        }
        if (!f) {
            for (i = 0; i < key; i++) {
                if (hash[i] == -1) {
                    hash[i] = item;
                    break;
                }
            }
        }
    }
}
void search(int item) {
    key = (item % size) - 1;
    flag = 0;
    if (hash[key] == item)
        flag = 1;
    else {
        for (i = key + 1; i < size; i++) {
            if (hash[i] == item) {
                flag = 1;
                key = i;
                break;
            }
        }
    }
    if (flag == 0) {
        for (i = 0; i < key; i++) {
            if (hash[i] == item) {
                flag = 1;
                key = i;
                break;
            }
        }
    }
    if (flag == 1) {
        found = 1;
        printf("Item searched was found at position %d!\n", key + 1);
    } else {
        key = -1;
        printf("Item searched was not found in the hash table\n");
    }
}
void display() {
    printf("Index\tElement\n");
    for (i = 0; i < size; i++)
        printf("%d\t%d\n", (i - 1 + size) % size, hash[i]);
    printf("\n");
}
int main() {
    int element, option;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    hash = (int *)malloc(size * sizeof(int));
    if (hash == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }
    for (i = 0; i < size; i++)
        hash[i] = -1;
    do {
        printf("\n1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            printf("Enter element to be searched: ");
            scanf("%d", &element);
            search(element);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 4);
    free(hash);
    return 0;
}

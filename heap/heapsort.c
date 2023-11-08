#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;
                                  
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void insert(int arr[], int *n, int key) {
    if (*n == 0) {
        arr[0] = key;
        (*n)++;
        return;
    }

    int i = (*n)++;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n) {
    printf("Min Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n = 0;
    int val;

    while (1) {
        printf("Enter a value to insert (or -1 to stop): ");
        scanf("%d", &val);

        if (val == -1)
            break;

        insert(arr, &n, val);
        printHeap(arr, n);
    }
 
 printf("\n");
    printf("\n");

    printf("Final ");
    printf("\n");
    
    printHeap(arr, n);

    return 0;
}

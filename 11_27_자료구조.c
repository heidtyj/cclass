#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} MaxHeap;

void init(MaxHeap *h) {
    h->size = 0;
}

void insert(MaxHeap *h, int value) {
    if (h->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    int i = h->size;
    h->data[i] = value;
    h->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent] >= h->data[i]) break;
        int temp = h->data[parent];
        h->data[parent] = h->data[i];
        h->data[i] = temp;
        i = parent;
    }
}

int delete(MaxHeap *h) {
    if (h->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    int i = 0;
    while (1) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        if (left < h->size && h->data[left] > h->data[largest])
            largest = left;
        if (right < h->size && h->data[right] > h->data[largest])
            largest = right;
        if (largest == i) break;
        int temp = h->data[i];
        h->data[i] = h->data[largest];
        h->data[largest] = temp;
        i = largest;
    }

    return root;
}

void printHeap(MaxHeap *h) {
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}

int main() {
    MaxHeap h;
    init(&h);

    insert(&h, 10);
    insert(&h, 40);
    insert(&h, 30);
    insert(&h, 50);
    insert(&h, 20);

    printHeap(&h);

    printf("delete: %d\n", delete(&h));
    printHeap(&h);

    return 0;
}
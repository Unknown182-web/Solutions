#include <iostream.h> 
#include <conio.h>      
#include <stdio.h>  
void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapifyMax(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapifyMax(heap, n, largest);
    }
}

void heapifyMin(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapifyMin(heap, n, smallest);
    }
}


void buildMaxHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(heap, n, i);
    }
}

void buildMinHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(heap, n, i);
    }
}


void deleteRootMax(int heap[], int &n) {
    if (n <= 0) return;
    heap[0] = heap[n - 1];
    n--;
    heapifyMax(heap, n, 0);
}

void deleteRootMin(int heap[], int &n) {
    if (n <= 0) return;
    heap[0] = heap[n - 1];
    n--;
    heapifyMin(heap, n, 0);
}

void main() {
    clrscr();  
    int size;


    cout << "Enter the number of elements for Max-Heap: ";
    cin >> size;
    int maxHeap[100]; 
    cout << "Enter the elements for Max-Heap: ";
    for (int i = 0; i < size; ++i) {
        cin >> maxHeap[i];
    }

    buildMaxHeap(maxHeap, size);
    cout << "Original Max-Heap:" << endl;
    printHeap(maxHeap, size);

    deleteRootMax(maxHeap, size);
    cout << "Max-Heap after deleting root:" << endl;
    printHeap(maxHeap, size);

        cout << "Enter the number of elements for Min-Heap: ";
    cin >> size;
    int minHeap[100]; 
    cout << "Enter the elements for Min-Heap: ";
    for (int i = 0; i < size; ++i) {
        cin >> minHeap[i];
    }

    buildMinHeap(minHeap, size);
    cout << "Original Min-Heap:" << endl;
    printHeap(minHeap, size);

    deleteRootMin(minHeap, size);
    cout << "Min-Heap after deleting root:" << endl;
    printHeap(minHeap, size);

    getch();  
}
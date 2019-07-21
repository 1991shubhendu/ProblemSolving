#include <iostream>
#include "heap.h"

void swap(int* num_1, int* num_2) {
    int temp = *num_1;
    *num_1 = *num_2;
    *num_2 = temp;
}

MinHeap::MinHeap(int capacity):capacity(capacity) {
    heap_size = 0;
    heap_arr = new int[capacity];
}

int MinHeap::get_parent_index(int child_index) { 
    int parent_index = (child_index-1)/2;
    return parent_index;
}

int MinHeap::get_left_child_index(int parent_index) { 
    int left_child_index = (parent_index*2)+1;
    return left_child_index;
}

int MinHeap::get_right_child_index(int parent_index) { 
    int right_child_index = (parent_index*2)+2;
    return right_child_index;
}

void MinHeap::insert(int key) {
    if (heap_size == capacity) {
        std::cout << "Stack overflown 02MH-E>" << "Heap Full : Remove some elements before inserting new elements" << std::endl;
        return;
    }

    heap_size++;
    int index = heap_size-1;
    heap_arr[index] = key;
    int parent_index = get_parent_index(index);
    while (index > 0 && heap_arr[parent_index] > heap_arr[index]) {
        swap(&heap_arr[index], &heap_arr[parent_index]);
        index = parent_index;
        parent_index = get_parent_index(index);
    }
}

int MinHeap::extract_min() {
    if (heap_size <= 0) {
        std::cout << "Extract operatioin failed \n";
        return INT_MAX;
    }
    int min_key = heap_arr[0];
    if (heap_size == 1) {
        heap_size--;
        return min_key;
    }
    heap_arr[0] = heap_arr[heap_size-1];
    heap_size--;
    min_heapify(0);
    return min_key;
}

void MinHeap::delete_key(int index) { 
    if (heap_size < 0) {
        std::cout << "Stack underflow 03MH-E>" << "Heap Empty:: Add some elements before delete operation" << std::endl;
        return;
    }
    update_key(index, INT_MIN);
    extract_min();
}

void MinHeap::update_key(int index, int new_value) { 
    heap_arr[index] = new_value;
    int parent_index = get_parent_index(index);
    while(index > 0 && heap_arr[parent_index] > heap_arr[index]) {
        swap(&heap_arr[index], &heap_arr[parent_index]);
        index = parent_index;
        parent_index = get_parent_index(index);
    }
}

void MinHeap::min_heapify(int parent_index) {
    int left_child_index = get_left_child_index(parent_index);
    int right_child_index = get_right_child_index(parent_index);
    int smallest_value_index = parent_index;

    if (left_child_index < heap_size && heap_arr[left_child_index] < heap_arr[parent_index]) {
        smallest_value_index = left_child_index;
    }

    if (right_child_index < heap_size && heap_arr[right_child_index] < heap_arr[smallest_value_index]) {
        smallest_value_index = right_child_index;
    }

    if (smallest_value_index != parent_index) {
        swap(&heap_arr[smallest_value_index], &heap_arr[parent_index]);
        min_heapify(smallest_value_index);
    }
}

int MinHeap::get_min() {
    if (heap_size < 0) {
        std::cout << "Extract operatioin failed \n";
        return INT_MAX;
    }
    int min_key = heap_arr[0];
    return min_key;
}

// Driver program to test above functions 
int main() 
{ 
    MinHeap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.delete_key(1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    std::cout << "Operation::Extract Min : " << h.extract_min() << std::endl; 
    std::cout << "Operation::Get Min Value in Heap : " << h.get_min() << std::endl; 
    std::cout << "Operation::Update heap key 2 with value 1" << std::endl; 
    h.update_key(2, 1); 
    std::cout << "Operation::Get Min value in Heap : "<< h.get_min() << std::endl; 
    return 0; 
}

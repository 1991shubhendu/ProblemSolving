#ifndef _HEAP_INCLUDED_H_
#define _HEAP_INCLUDED_H_
class MinHeap{
    private:
        int* heap_arr;
        int capacity;
        int heap_size;
    public:
        MinHeap(int capacity);
        int extract_min();
        void insert(int key);
        void update_key(int index, int new_value);
        void min_heapify(int parent_index);
        int get_parent_index(int child_index);
        int get_left_child_index(int parent_index);
        int get_right_child_index(int parent_index);
        void delete_key(int key);
        int get_min();
};
#endif // _HEAP_INCLUDED_H_

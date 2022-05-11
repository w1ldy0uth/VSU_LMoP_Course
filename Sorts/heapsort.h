#pragma once
#include <vector>

void siftdown(std::vector<int>& arr, int start, int end) {
    int root = start;
    while (true) {
        int child = root * 2 + 1;
        if (child > end)
            break;
        if (child + 1 <= end && arr[child] < arr[child+1])
            child += 1;
        if (arr[root] < arr[child]) {
            std::swap(arr[root], arr[child]);
            root = child;
        }
        else
            break;
    }
}

void heapSort(std::vector<int>& arr) {
    for (int start = (int) (arr.size()-2) / 2; start > -1; --start)
        siftdown(arr, start, (int) arr.size()-2);
    for (int end = (int) arr.size()-1; end > 0; --end) {
        std::swap(arr[0], arr[end]);
        siftdown(arr, 0, end-1);
    }
}
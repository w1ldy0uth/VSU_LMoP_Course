#pragma once
#include <vector>

int partition(std::vector<int>& arr, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (arr[i] < arr[pivot]) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
    std::swap(arr[j], arr[pivot]);
    return j;
}

void quickSortInner(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSortInner(arr, start, p - 1);
        quickSortInner(arr, p + 1, end);
    }
}

void quickSort(std::vector<int>& arr) {
    quickSortInner(arr, 0, (int) arr.size()-1);
}
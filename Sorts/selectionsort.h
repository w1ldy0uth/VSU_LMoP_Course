#pragma once
#include <vector>

void selectionSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int min_idx = i;
        for (int j = i+1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}
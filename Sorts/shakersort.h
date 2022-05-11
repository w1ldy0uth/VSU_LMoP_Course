#pragma once
#include <vector>

void shakerSort(std::vector<int>& arr) {
    bool swapped = true;
    int begin = 0, end = (int) arr.size() - 1;

    while (swapped) {
        swapped = false;

        for (int i = begin; i < end; ++i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        end--;

        for (int i = end-1; i > begin - 1; --i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }

        begin++;
    }
}
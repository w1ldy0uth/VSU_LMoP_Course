#pragma once
#include <vector>

int getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1)
        gap = 1;

    return gap;
}

void combSort(std::vector<int>& arr) {
    int size = (int) arr.size();
    int gap = size;
    bool swapped = true;

    while (gap != 1 or swapped) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i+gap]) {
                std::swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}
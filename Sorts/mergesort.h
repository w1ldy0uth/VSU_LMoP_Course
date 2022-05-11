#pragma once
#include <vector>

void mergeSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = (int) arr.size() / 2;
        std::vector<int> leftHalf(arr.begin(), arr.begin()+mid);
        std::vector<int> rightHalf(arr.begin()+mid, arr.begin()+(int)arr.size());

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        int i = 0, j = 0, k = 0;

        while (i < leftHalf.size() && j < rightHalf.size()) {
            if (leftHalf[i] < rightHalf[i]) {
                arr[k] = leftHalf[i];
                i++;
            } else {
                arr[k] = rightHalf[j];
                j++;
            }
            k++;
        }

        while (i < leftHalf.size()) {
            arr[k] = leftHalf[i];
            i++;
            k++;
        }

        while (j < rightHalf.size()) {
            arr[k] = rightHalf[j];
            j++;
            k++;
        }
    }
}
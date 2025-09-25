#include <iostream>
#include <vector>

/*
    《王道数据结构》P19T01;
    function:delete the min element of the arr and replace it with the last element;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

template <typename T>
T solve(std::vector<T>& arr)
{
    if (arr.empty()) {
        std::cout << "WRONG!";
        return std::nullopt;
    }

    T min = arr[0];
    int n = arr.size(), idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            idx = i;
        }
    }

    arr[idx] = arr.back();
    arr.pop_back();
    return min;
}
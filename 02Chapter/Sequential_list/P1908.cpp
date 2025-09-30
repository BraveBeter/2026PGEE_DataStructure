#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T08;
    function:find the index of X in the sorted array;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
void solve(std::vector<T>& arr, int x)
{
    int idx = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (idx < arr.size() && arr[idx] == x) {
        if (idx + 1 < arr.size())
            std::swap(arr[idx], arr[idx + 1]);
    } else {
        arr.insert(arr.begin() + idx, x);
    }
}
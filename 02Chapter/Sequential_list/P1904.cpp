#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T04;
    function:delete the elements which are between s and t in the array;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
void solve(std::vector<T>& arr, T s, T t)
{
    if (s > t) {
        std::cout << "interval is invalid";
        return;
    }
    if (arr.empty()) {
        std::cout << "Empty Array";
        return;
    }

    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s <= arr[i] && arr[i] <= t)
            cnt++;
        else
            arr[i - cnt] = arr[i];
    }
    while (cnt > 0) {
        cnt--;
        arr.pop_back();
    }
}
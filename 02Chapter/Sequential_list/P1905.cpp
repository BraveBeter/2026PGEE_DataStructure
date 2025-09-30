#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T05;
    function:Remove duplicates to make all elements in the sorted array unique.;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
void solve(std::vector<T>& arr)
{
    int n = arr.size(), cnt = 0;
    T last = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == last)
            cnt++;
        else {
            arr[i - cnt] = arr[i];
            last = arr[i];
        }
    }

    while (cnt > 0) {
        cnt--;
        arr.pop_back();
    }
}
#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T03;
    function:delete all elements which are equal to X in the array;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
void solve(std::vector<T>& arr, T x)
{
    int n = arr.size(), cnt = 0;

    for (int i = 0; i < n; i++) {
        if (x == arr[i])
            cnt++;
        else
            arr[i - cnt] = arr[i];
    }
    while (cnt > 0) {
        cnt--;
        arr.pop_back();
    }
}

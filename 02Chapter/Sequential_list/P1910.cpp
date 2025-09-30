#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T10;
    function:change (a1, a2,...,an) into (ap, ap+1,...,an,a1,a2,...,ap-1);
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

void reverseSpecialIntervalArray(std::vector<int>& arr, int begin, int end)
{
    int n = arr.size(), len = end - begin + 1;
    if (begin < 0 || end >= n || len < 0) {
        std::cout << "WRONG!";
        return;
    }

    for (int i = 0; i < len / 2; i++) {
        std::swap(arr[begin + i], arr[end - i]);
    }
}

void solve(std::vector<int>& arr, int p)
{
    int n = arr.size();
    if (p > n || p < 0) {
        std::cout << "Wrong";
        return;
    }
    reverseSpecialIntervalArray(arr, 0, p - 1);
    reverseSpecialIntervalArray(arr, p, n - 1);
    reverseSpecialIntervalArray(arr, 0, n - 1);
}
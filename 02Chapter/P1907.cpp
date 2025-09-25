#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T07;
    function:change (a1, a2, ...,am, b1, b2, ...,bn) into (b1, b2, ..., bn, a1, a2, ..., am);
    Time Complexity :O(n + m);
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

void solve(std::vector<int>& arr, int n, int m)
{
    reverseSpecialIntervalArray(arr, 0, n - 1);
    reverseSpecialIntervalArray(arr, n, n + m - 1);
    reverseSpecialIntervalArray(arr, 0, n + m - 1);
}

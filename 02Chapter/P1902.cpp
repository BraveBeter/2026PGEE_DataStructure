#include <iostream>
#include <vector>
/*
    《2026王道数据结构》综合题P19T02
    function:Reverse the specified interval of an array;
    Time Complexity :O(len);
    Space Complexity:O(1);
*/

void solve(std::vector<int>& arr, int begin, int end)
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

#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T06;
    function:Merge two sorted arrays into a single sorted array;
    Time Complexity :O(n + m);
    Space Complexity:O(n + m);
*/
std::vector<int> solve(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
    int n = arr1.size(), m = arr2.size();
    std::vector<int> res(n + m);

    int p1 = 0, p2 = 0, idx = 0;
    while (p1 < n && p2 < m) {
        if (arr1[p1] < arr2[p2])
            res[idx++] = arr1[p1++];
        else
            res[idx++] = arr2[p2++];
    }

    while (p1 < n)
        res[idx++] = arr1[p1++];
    while (p2 < m)
        res[idx++] = arr2[p2++];
    return res;
}
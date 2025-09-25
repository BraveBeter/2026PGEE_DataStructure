#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P20T13;
    function: find the smallest positive integer which does not occur in the array；
    Time Complexity :O(nlogn); O(n);
    Space Complexity:O(1); O(n);
*/

// O(n) + O(n)
int solve1(const std::vector<int>& arr)
{
    int n = arr.size();
    if (n == 0)
        return 1;

    std::vector<bool> rec(n + 2);
    for (int num : arr) {
        if (num <= n) {
            rec[num] = true;
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        if (rec[i] == false) {
            return i;
        }
    }

    return -1;
}

// O(nlog(n)) + O(1)
int solve2(std::vector<int>& arr)
{
    int n = arr.size();
    if (n == 0)
        return 1;

    std::sort(arr.begin(), arr.end());

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans == arr[i])
            ans++;
    }
    return ans;
}
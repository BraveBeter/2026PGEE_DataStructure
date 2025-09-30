#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T11; leetcodeT4;
    function:find the median of two sorted arrays;
    Time Complexity :O(log(n + m));
    Space Complexity:O(1);
*/
int solve(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
    int n = arr1.size(), m = arr2.size();
    return findTheKthElementOfTwoSortedArrays(arr1, arr2, (n + m + 1) / 2);
}

int findTheKthElementOfTwoSortedArrays(const std::vector<int>& arr1,
    const std::vector<int>& arr2, int k)
{
    int n = arr1.size(), m = arr2.size();

    if (k == n + m)
        return std::max(n > 0 ? arr1.back() : INT32_MIN, m > 0 ? arr2.back() : INT32_MIN);

    int begin1 = 0, begin2 = 0;
    while (true) {
        if (k == 1)
            return std::min(n > begin1 ? arr1[begin1] : INT32_MAX,
                m > begin2 ? arr2[begin2] : INT32_MAX);
        if (begin1 == n)
            return arr2[begin2 + k - 1];
        if (begin2 == m)
            return arr1[begin1 + k - 1];

        int idx1 = std::min(begin1 + k / 2, n) - 1;
        int idx2 = std::min(begin2 + k / 2, m) - 1;
        if (arr1[idx1] >= arr2[idx2]) {
            k -= (idx2 - begin2 + 1);
            begin2 = idx2 + 1;
        } else {
            k -= (idx1 - begin1 + 1);
            begin1 = idx1 + 1;
        }
    }
    return -1;
}
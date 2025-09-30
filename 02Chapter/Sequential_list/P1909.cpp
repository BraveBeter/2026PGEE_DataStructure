#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P19T09;
    function:output the common elements in three sorted arrays line by line;
    Time Complexity:O(max(n, m, k));
    Space Complexity:O(1);
*/
void solve(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C)
{
    std::vector<int> p(3);
    int n = A.size(), m = B.size(), k = C.size();

    while (p[0] < n && p[1] < m && p[2] < k) {
        if (A[p[0]] == B[p[1]] && B[p[1]] == C[p[2]]) {
            std::cout << A[p[0]] << '\n';
            p[0]++, p[1]++, p[2]++;

        } else {
            int max = std::max({ A[p[0]], B[p[1]], C[p[2]] });

            while (p[0] < n && A[p[0]] < max)
                p[0]++;
            while (p[1] < m && B[p[1]] < max)
                p[1]++;
            while (p[2] < k && C[p[2]] < max)
                p[2]++;
        }
    }
}
#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P20T14;
    function:find the min distance of the special tuples;
    Time Complexity :O(max(n, m, k));
    Space Complexity:O(1);
*/
int solve(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C)
{
    std::vector<int> p(3), lens(3);
    lens[0] = A.size(), lens[1] = B.size(), lens[2] = C.size();

    auto check = [&]() -> bool {
        for (int i = 0; i < 3; i++) {
            if (p[i] >= lens[i]) {
                return false;
            }
        }
        return true;
    };
    int ans = INT32_MAX;
    while (check()) {
        int distance = abs(A[p[0]] - B[p[1]]) + abs(A[p[0]] - C[p[2]]) + abs(B[p[1]] - C[p[2]]);
        ans = std::min(ans, distance);

        if (A[p[0]] == B[p[1]] && B[p[1]] == C[p[2]]) {
            for (int i = 0; i < 3; i++) {
                p[i]++;
            }
        } else {
            int min_val = std::min({ A[p[0]], B[p[1]], C[p[2]] });
            if (A[p[0]] == min_val)
                p[0]++;
            else if (B[p[1]] == min_val)
                p[1]++;
            else
                p[2]++;
        }
    }
    return ans;
}

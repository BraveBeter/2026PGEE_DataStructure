#include <iostream>
#include <string>
#include <vector>
/*
   《2026王道数据结构》第四章KMP算法实现;
    function:String Matching, Returns the Index at the first match of the string;
    Time Complexity :O(n + m);
    Space Complexity:O(m);
*/

std::vector<int> get_next(const std::string& t)
{
    int m = t.size();
    std::vector<int> next(m + 1);
    next[0] = -1;

    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || t[i] == t[j]) {
            i++, j++;
            next[i] = j;
        } else
            j = next[j];
    }
    return next;
}

std::vector<int> get_nextval(const std::string& t)
{
    int m = t.size();
    std::vector<int> nextval(m + 1);
    nextval[0] = -1;

    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || t[i] == t[j]) {
            i++, j++;
            if (t[i] != t[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }

    return nextval;
}

int KMP(const std::string& s, const std::string& t)
{
    int n = s.size(), m = t.size();
    std::vector<int> next = get_next(t);
    std::vector<int>& jump = next;
    // std::vector<int> nextval = get_nextval(t);
    // std::vector<int> &jump = nextval;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || s[i] == t[j])
            i++, j++;
        else
            j = jump[j];

        if (j == m)
            return i - j;
    }
    return -1;
}
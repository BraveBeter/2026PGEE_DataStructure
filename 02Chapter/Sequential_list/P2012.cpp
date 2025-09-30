#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P20T12;
    function:function: find the element which occurs more than half the length of the array;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
int solve(const std::vector<int>& arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;

    int main_element = arr[0], time = 1;
    for (int i = 1; i < n; i++) {
        if (main_element != arr[i]) {
            time--;
        } else {
            time++;
        }

        if (time == 0) {
            time = 1;
            main_element = arr[i];
        }
    }

    int check_cnt = 0;
    for (int num : arr) {
        if (num == main_element) {
            check_cnt++;
        }
    }
    return (check_cnt * 2 > n ? main_element : -1);
}

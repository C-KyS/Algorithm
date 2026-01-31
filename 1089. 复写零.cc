// 题目链接: https://leetcode.cn/problems/duplicate-zeros/submissions/695543316/

#include <vector>

class Solution
{
public:
    // 1. 查找最后元素cur, 及des(一般固定为n-1, 特殊情况下不为n-1, 因此des也会变化)
    int findLastCur(std::vector<int> &arr, int &input_des)
    {
        int n = arr.size();
        int cur = 0;
        int des = -1;
        while (cur < n)
        {
            if (arr[cur] != 0)
                des++;
            else
                des += 2;

            if (des == n)
            {
                arr[arr.size() - 1] = 0;
                des -= 2;
                cur--;
                break;
            }
            if (des == n - 1)
                break;

            cur++;
        }

        input_des = des;
        return cur;
    }

    void duplicateZeros(std::vector<int> &arr)
    {
        int des = -1;
        // 1. 查找最后元素cur, 及des(一般固定为n-1, 特殊情况下不为n-1, 因此des也会变化)
        int cur = findLastCur(arr, des);
        // cout << cur <<" & " << des;
        // 2. cur, des已确定，从后向前逐渐覆盖
        while (cur >= 0)
        {
            if (arr[cur] != 0)
                // cur位置非零, des只覆盖一步
                arr[des--] = arr[cur--];
            else
            { // cur位置为零, des覆盖两步
                arr[des--] = 0;
                arr[des--] = 0;
                cur--;
            }
        }
    }
};
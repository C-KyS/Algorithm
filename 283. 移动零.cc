// 题目链接: https://leetcode.cn/problems/move-zeroes/description/
// 博客链接: https://blog.csdn.net/cyh20041102/article/details/157555987?spm=1011.2415.3001.10575&sharefrom=mp_manage_link

class Solution {
public:
    void exchange(int &a, int &b)
    {
        int tmp = a;
        a=b;
        b=tmp; 
    }

    void moveZeroes(vector<int>& nums) {
        int des = -1; // 初始des为-1, 即cur-1
        for(int cur = 0; cur < nums.size(); cur++)
        {
            
            if(nums[cur] == 0)
            {   // 当前处理数字为0, 直接纳入不作多余处理
                continue;
            }
            else
            {   // 当前处理数字为非0, 将当前数组第一个0与其对换位置，再纳入
                exchange(nums[des+1], nums[cur]);
                des++;
            }
        }
    }
};
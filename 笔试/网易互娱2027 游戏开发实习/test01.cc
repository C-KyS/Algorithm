//  n个元素数组, 编号为1~n
// 每次新来的需放置在与已放置元素距离最远的位置, 距离计算公式:|i-j|
// 输入: n, m (分别为数组大小和操作次数)
//       接下来会有m行, 每行有两个整数t_i, id_i
//       t_i, id_i (分别为第i次操作的具体内容和操作对象编号)
//                 (t_i=1表示id_i元素到达, t_i=2表示id_i元素离开)
// 输出: 若t_i=1, 则输出id_i元素的最终位置编号(1~n)
//       若t_i=2, 则输出id_i元素离开的位置编号(1~n)
// 输入示例1:
// 3 3
// 1 1
// 2 1
// 1 2
// 输出示例1:
// 1
// 1
// 1
// 说明:
// 在这个样例中
// 事件一：守护者 1 到达，迷宫为空，选择位置 1；
// 事件二：守护者 1 离开，释放位置 1；
// 事件三：守护者 2 到达，迷宫为空，选择位置 1


// 输入示例2:
// 3 7
// 1 1
// 2 2
// 1 1
// 1 2
// 2 2
// 2 1
// 1 2
// 输出示例2:
// 1
// 3
// 3
// 1
// 1

// 输入用例3:
// 7 9
// 1 1
// 1 2
// 1 3
// 2 1
// 1 4
// 2 2
// 1 5
// 1 6
// 1 7
// 输出用例3:
// 1
// 7
// 4
// 1
// 1
// 7
// 7
// 2
// 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> seats(n + 1, 0);     // 0表示空位, 非0表示被占用的元素id
    vector<int> positions(m + 1, 0); // 记录每个id的当前位置

    for (int i = 1; i <= m; i++)
    {
        int t, id;
        cin >> t >> id;
        if (t == 1)
        { // 元素到达
            int bestPos = -1;
            int maxDist = -1;

            for (int j = 1; j <= n; ++j)
            {
                if (seats[j] == 0)
                { // 空位
                    int leftDist = (j == 1) ? n : j - 1;
                    int rightDist = (j == n) ? n : n - j;
                    for (int k = 1; k <= n; ++k)
                    {
                        if (seats[k] != 0)
                        {
                            leftDist = min(leftDist, abs(j - k));
                            rightDist = min(rightDist, abs(j - k));
                        }
                    }
                    int dist = min(leftDist, rightDist);
                    if (dist > maxDist)
                    {
                        maxDist = dist;
                        bestPos = j;
                    }
                }
            }
            seats[bestPos] = id;
            positions[id] = bestPos;
            cout << bestPos << endl;
        }
        else if (t == 2)
        { // 元素离开
            int pos = positions[id];
            seats[pos] = 0;
            cout << pos << endl;
            positions[id] = 0;
        }
    }
    return 0;
}

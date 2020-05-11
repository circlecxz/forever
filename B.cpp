/*
 题解：
 将输入数据从小到大排序，动态规划递推，当前位置为i，从0到i - 1遍历， 如果遍历的位置与当前位置数相差d，
 dp[i] = max(dp[j] + 1, dp[i])
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<int> data(n), dp(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    sort(data.begin(), data.end());  //序列从小到大排序
    int ans = 0;
    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
        if(data[i] - data[j] > d) {
            dp[i] = dp[i - 1] + 1;
        }else {
            dp[i] = dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    
    printf("%d\n", ans);
    return 0;
}

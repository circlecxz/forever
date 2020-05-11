/*
 题解：
 结构体存放到达时间，需要时间，等待时常;
 维持一个变量记录开始时间，初始化开始时间为0，若当前到达时间大于等于开始时间，则当前同学开始时间即为到达时间，
 同时更新开始时间为服务开始时间加耗时，若当前到达时间小于开始时间，且到达时间加等待时间大于等于开始时间，输出开始时间，
 更新开始时间为开始时间加上耗时，其余情况输出-1
 */

#include <cstdio>
#include <vector>
using namespace std;

struct Stu {
    int arriveTime, needTime, waitTime;
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Stu> stu(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &stu[i].arriveTime, &stu[i].needTime, &stu[i].waitTime);
    }
    int startTime = 0;
    for(int i = 0; i < n; ++i) {
        if(stu[i].arriveTime >= startTime) {
            startTime = stu[i].arriveTime;
            printf("%d", startTime);
            startTime += stu[i].needTime;
            
        }else if(stu[i].arriveTime < startTime && stu[i].waitTime + stu[i].arriveTime >= startTime) {
            printf("%d", startTime);
            startTime += stu[i].needTime;
        }else {
            printf("-1");
        }
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}


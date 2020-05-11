/*
 题解:
 输入数据同时计算数据的总合，双层for循环计算总和减去其中两个数得三元组的和。其中存在一组三元组为10的倍数（包括0），则跳出
 双层循环，同时标记存在和为10倍数的三元组。最后依据标记输出权值
 */


#include <cstdio>

int main() {
    int T;         // 数据组数
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        int data[5], sum = 0, remain = 0;    // data存放输入的5个整数, sum计算总和, remain其中三个数的和
        bool flag = false;
        for(int j = 0; j < 5; ++j) {
            scanf("%d", &data[j]);
            sum += data[j];
        }
        for(int j = 0; j < 5; ++j) {
            for(int k = j + 1; k < 5; ++k) {
                remain = sum - data[j] - data[k];    //计算三元组的和
                if(remain % 10 == 0) {              //判断三元组的和是否为10的倍数
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) {    //三元组的和为10的倍数
            int result = (sum - remain) % 10;    //计算其余两数和对10取余
            printf("%d\n", result);
        }else {     //三元组的和不是10的倍数
            printf("-1\n");
        }
    }
    return 0;
}

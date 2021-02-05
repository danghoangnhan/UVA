#include<cstdio>
 using namespace std;
int main()
{
    int M, N;
    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &N);
        int ans[1001], nOfans = 0, sum = 0; // 分組組數: nOfans
        for (int i = 2; sum + i <= N; i++)
        {                      // 分組人數從2 (i值)開始往上分配
            sum += i;          // 用sum值來檢驗分組數是否已達上限
            ans[nOfans++] = i; // ans[nOfans]: 存分配好的分組人數
        }
        int left = N - sum; // 剩餘值 left用來繼續分配,由右至左每次分配值1
        for (int i = nOfans - 1; left > 0; i--, left--)
        {
            if (i < 0)
                i = nOfans - 1; // 如果已經分配到最左邊,下次從最右邊開始往左分配
            ans[i]++;           // 用加1方式分配剩餘值
        }
        printf("%d", ans[0]);
        for (int i = 1; i < nOfans; i++)
            printf(" %d", ans[i]);
        printf("\n");
        if (M)
            printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10002;
int arr[maxn];
int test, num, sum, row, col, neg;
string str, trash;
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        arr[i] = 0;
    }
}
int maxSubArraySum()
{
    long long int maxValue = INT_MIN;
    long long int currentValue = 0;

    for (int i = 0; i < test; i++)
    {
        currentValue = currentValue + arr[i];
        if (maxValue < currentValue)
            maxValue = currentValue;

        if (currentValue < 0)
            currentValue = 0;
    }
    return maxValue;
}
int main()
{
    while (cin >> test)
    {
        if (test == 0)
            break;
        init();  //初始化
        num = 0; //有幾個數字了
        sum = 0; //加總數
        neg = 0; //是不是負數
        int i = test;
        while (i--)
        {
            cin >> sum;
            arr[num] = sum;
            num++;
        }
        for (int i = 0; i < num; i++)
            cout << arr[i] << " ";
        cout << endl;
        long long int ans = maxSubArraySum();

        if (ans >= 0)
        {
            cout << "The maximum winning streak is " << ans << "." << endl;
        }
        else
        {
            cout << "Losing streak." << endl;
        }
    }
    return 0;
}

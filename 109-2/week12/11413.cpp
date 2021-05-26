#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m, a[N];

bool judge(int k)
{
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum > k) {sum = a[i]; cnt++;}
    }
    return cnt < m;
}

int bs(int lo, int hi)
{
    int ret = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(judge(mid)) {ret = mid; hi = mid - 1;}
          else lo = mid + 1;
    }
    return ret;
}

int main()
{
    freopen("11413.in","r",stdin); 
    freopen("11413.out","w",stdout); 		
    while(~scanf("%d%d", &n, &m)) {
        int lo = 0, hi = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            lo = max(lo, a[i]);
            hi += a[i];
        }
        printf("%d\n", bs(lo, hi));
    }
    return 0;
}

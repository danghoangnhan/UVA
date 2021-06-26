#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int T,n,m,k,Case = 0,a[maxn],cnt[maxn];

int main() {
	freopen("11536.in","r",stdin);
    freopen("11536.out","w",stdout);
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&k);
        memset(cnt,0,sizeof(cnt));
        a[1] = 1; a[2] = 2; a[3] = 3;
        if(n>3) for(int i=4;i<=n;i++) {
            a[i] = (a[i-1]+a[i-2]+a[i-3])%m + 1;
        }
        int ans = 2000000000;
        int rear = 0,last = 1,c = 0;
        while(true) {
            if(c == k) {
                cnt[a[last]] -- ;
                if(cnt[a[last]] == 0 && a[last] <= k) c--;
                last++;
                if(c == k) ans = min(ans , rear - last + 1);
            }
            else {
                rear ++;
                if(rear > n) break;
                cnt[a[rear]]++;
                if(cnt[a[rear]] == 1 && a[rear] <= k) c++;
 
                if(c == k) ans = min(ans , rear - last + 1);
 
            }
        }
        printf("Case %d: ",++Case);
        if(ans != 2000000000) printf("%d\n",ans);
        else printf("sequence nai\n");
    }
    return 0;
}

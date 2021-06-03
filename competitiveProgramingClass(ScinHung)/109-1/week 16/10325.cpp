#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[20];
ll gcd(ll a,ll b){ return b ? gcd(b,a%b):a;}
ll lcm(ll a,ll b){ ll tmp=gcd(a,b); return a/tmp*b;}
ll n, m,sum,LCM,ones;

int main()
{
  while(~scanf("%lld%lld",&n,&m)) {

    for(ll i=0;i<m;i++) scanf("%lld",&p[i]);

        sum=0;

    for(ll i=1;i<(1<<m);i++) {
        LCM=1;
        ones=0;
      for(ll j=0;j<m;j++) {
        if(i&(1<<j)) {
           LCM=lcm(LCM,p[j]);
           if(LCM>n) break;
           ones++;
        }
      }

      if(LCM>n) continue;
      if(ones%2) sum+=n/LCM;
            else sum-=n/LCM;       
    }

    printf("%lld\n",n-sum);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long m,n,flag;
void dfs(long ans, long step)
{
  if(ans>n||ans<1) return;
  if(ans==m) {flag=1; return;}
  dfs(ans+2*step+1,step+1);
  dfs(ans-2*step-1,step+1);
}
int main(){   
  while(scanf("%ld%ld",&n,&m)==2,n+m) {
    if(n>=49) printf("Let me try!\n");
      else {
             flag=0;
             dfs(1,1);
             if(flag) printf("Let me try!\n");
               else printf("Don't make fun of me!\n");
            }
  }
  return 0;
}

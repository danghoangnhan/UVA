#include <bits/stdc++.h>
const int prime[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int multable[5000],top;
void lmul(int a[], int num)
{
  int i, pre;
  pre = 0;
  for (i = 0; i <= top; i++)
  {
    a[i]  = a[i] * num + pre;
    pre   = a[i] / 10000;
    a[i] %= 10000;
  }
  if (pre > 0)
  {
    a[i] = pre;
    top = i;
  }
  else
    top = i - 1;
}
void div_c(int n, int r)
{
  int i, j, num;
  i = (r > n / 2) ? r + 1 : n - r + 1;
  for (; i <= n; i++)
  {
    num = i;
    j = 0;
    while (j < 20)
    {
      if (num % prime[j] == 0)
      {
        multable[prime[j]]--;
        num /= prime[j];
        j = 0;
      }
      else
        j++;
    }
    if (num != 0 && num != 1)
      multable[num]--;
  }
  i = (r > n / 2) ? n - r : r;
  for (; i > 1; i--)
  {
    num = i;
    j = 0;
    while (j < 20)
    {
      if (num % prime[j] == 0)
      {
        multable[prime[j]]++;
        num /= prime[j];
        j = 0;
      }
      else
        j++;
    }
    if (num != 0 && num != 1)
      multable[num]++;
  }
}
void mul_c(int n, int r)
{
  int i, j, num;
  i = (r > n / 2) ? r + 1 : n - r + 1;
  for (; i <= n; i++)
  {
    num = i;
    j = 0;
    while (j < 20)
    {
      if (num % prime[j] == 0)
      {
        multable[prime[j]]++;
        num /= prime[j];
        j = 0;
      }
      else
        j++;
    }
    if (num != 0 && num != 1)
      multable[num]++;
  }
  i = (r > n / 2) ? n - r : r;
  for (; i > 1; i--)
  {
    num = i;
    j = 0;
    while (j < 20)
    {
      if (num % prime[j] == 0)
      {
        multable[prime[j]]--;
        num /= prime[j];
        j = 0;
      }
      else
        j++;
    }
    if (num != 0 && num != 1)
      multable[num]--;
  }
}
int main()
{
  int N,M,n,r,i,j,num,err;
  int a[30];
  while(scanf("%d %d" ,&N,&M)!=EOF) {
    for(i=0;i<5000;i++) multable[i] = 0;
    err = 2;
    top = 0;
    a[0] = 1;
    for(i=1;i<29;i++) a[i]=0;
    for(i=0;i<N;i++) {
      scanf("%d %d" ,&n,&r);
      if(n!=0 && r!=0) mul_c(n,r);
    }
    for(i=0;i<M;i++) {
       scanf("%d %d" ,&n,&r);
       if(n!=0 && r!=0) div_c(n,r);
    }
    for(i=2;i<5000;i++) {
        if(multable[i] < 0) {err = 0; break; }
    }
    if(err > 0)
     for(i=2;i<5000;i++) {
        for(j=multable[i] ; j>0 ; j--) {
          lmul(a,i);
          if(top>24) break;
         }
        if(top>24) { err = -1; break; }
     }
    if(err>0) {
      printf("%d" ,a[top]);
      for(i=top-1;i>=0;i--) printf("%04d" ,a[i]);
    } else printf("%d" ,err);
    printf("\n");
  }
  return 0;
}




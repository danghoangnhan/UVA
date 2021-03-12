#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 10010;
int n;
int arr[MAXN];
bool judge(int* a){
    for(int i=0; i<n; ++i){
        for(int j=1; i+2*j<n; ++j){ 
            if(a[i]<a[i+j]&&a[i+j]<a[i+2*j] ||a[i]>a[i+j]&&a[i+j]>a[i+2*j] )
                return false;
        }
    }
    return true; 
}
int main(){ 
    int x;
    while(~scanf("%d:", &n) && n){
      
        for(int i=0; i<n; ++i){
            scanf("%d", &x);
            arr[x] = i;
        }
        if(judge(arr)) puts("yes");
        else puts("no");
    }
    return 0;
}


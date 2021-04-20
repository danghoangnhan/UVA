#include <bits/stdc++.h>
#define MAXN 52
using namespace std;
long long int testCase,peg;
long long int diff;

int main(){
    long long int arr[MAXN]={0};
    diff=2;
    arr[1]=1;
    for(long long int i=2;i<MAXN;i++){
        arr[i]=arr[i-1]+diff;
        
        if(i%2==0)
            diff+=2;

    }

    cin>>testCase;
    while(testCase--){
        cin>>peg;
        cout<<arr[peg]<<endl;
    }
    return 0;
}
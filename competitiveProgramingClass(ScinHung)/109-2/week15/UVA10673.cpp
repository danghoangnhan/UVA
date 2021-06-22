#include <bits/stdc++.h>

using namespace std;
long long int testCase,a,b,x,y,d,c,lcm,k;

long long int extendGcd(long long int a,long long int b,long long int c,long long int &x,long long int &y){
    if(b==0){
        x=c/a;
        y=0;
        return a;
    }
    int d = extendGcd(b,a%b,c,x,y);
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return d;
}

int main(){
    cin>>testCase;
    while(testCase--){
        cin>>c>>k;
        
        a = c / k;
        b = (long long int)ceil(c / (double)k);
        long long int d = extendGcd(a, b, c, x, y);
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
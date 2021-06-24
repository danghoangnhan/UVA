
#include <bits/stdc++.h>

long long int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b){
        d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    }
    else
        x = 1, y = 0;
    return d;
} // ax+by=1 ax同餘 1 mod b

long long int testCase;
long long int c1, c2, n1, n2;
using namespace std;
int main(){
    while(cin>>testCase&&testCase!=0){
        cin>>c1>>c2>>n1>>n2;
    }
    return 0;
}



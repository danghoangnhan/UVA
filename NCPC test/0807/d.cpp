#include <bits/stdc++.h>

using namespace std;
long long int x,y;
const long long int neg = -1e6;
long long int ans;

long long int step(long long int a,long long int b){
    // cout << a << " " << b << endl;
    if(a==x&&b==y){
        return 0;
    }
    else if(b==y&&a!=x){
        // cout<<"catch"<<endl;
        return neg;
    }
    else{
        
        if (a <= x)
        {
            return 1 + step(a + 1, b + 2);
        }
        else
            return 1 + step(a - 1, b + 2);
    } 
}
int main(){
    cin>>x>>y;
    if(y<0||y%2!=0){
        cout<<-1<<endl;
    }
    else{
        ans = step(0,0);
        if(ans>=0){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }
       
    }
    
    return 0;
}
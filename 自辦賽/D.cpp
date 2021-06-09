#include <bits/stdc++.h>

using namespace std;
long long int testCase;
long long int x;
long long int cnt;
int main(){
    cin>>testCase;
    while(testCase--){
        cin>>x;
        cnt=0;
        
        while(x>9){
            long long int sample = x;
            long long int maximum = -1;
            while(sample>0){
                maximum = max(maximum, sample % 10);
                sample/=10;
            }
        x-=maximum;
        cnt++;
        //cout<<x<<" "<<maximum<<endl;
        }
        if(x>0){
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
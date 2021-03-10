#include <bits/stdc++.h>
using namespace std;

long long int testCase,R,L,Maxcost;
//greedy method
int main(){
    cin>>testCase;
    while(testCase--){
        cin>>R>>L;
        Maxcost = 0;
        long long int arr[R+1][L+1];
        for(long long int b = 1; b<=R; b++){
            cin>>arr[0][b];
            for(long long int c = 1;c<=arr[0][b];c++){
                cin>>arr[c][b];
            }
        }
        cout<<"done"<<endl;
    }
    return 0;
}
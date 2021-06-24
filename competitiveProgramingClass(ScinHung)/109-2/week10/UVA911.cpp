#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
long long int n,k;
long long int arr[maxn];
long long int currentNumber;
long long int up,down;
long long int length;
int main(){
    freopen("911.in", "r", stdin);
    freopen("911_daniel.out", "w", stdout);
    while(cin >>n){
        memset(arr,0,sizeof(arr));   
        up=1;
        down=1;
        cin>>length;
        for(long long int i=0;i<length;i++){
            cin>>currentNumber;
            for(long long int k=1;k<=currentNumber;k++){
                if(arr[k]==0){
                    arr[k]=1;
                }
                else{
                    down*=k;
                }
            }
        }
        for(long long int i=1;i<=n;i++){
            if(arr[i]==0){
                up*=i;
            }
        }
        cout<<up/down<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define n 2703664
using namespace std;

long long int numb,testCase,ans,sample,index,left,right;
long long int arr[n];

int main()
{
    for(long long int i=0;i<n;i++)
        arr[i]=1;

    arr[0]=0,arr[1]=0,testCase=1;
    for(long long int i=2;arr[i]<n;i++){
            if(arr[i]==1){
                for(long long int j=2;i*j<n;j++){
                    arr[i*j]=arr[j]+arr[i];
            }
        }
    }
    for(long long int i=2;i<n;i++)
         arr[i]+=arr[i-1];

    while(cin>>numb&&numb>=0){
            if(numb==0){
                    cout<<"Case "<<testCase++<<": "<<"0!"<<endl;
                    continue;

            }
            ans = -1;
            long long int left=0;
            long long int right=n-1;
            long long int between;

            while(left<=right){
                between = (left+right)/2;
//                cout<<left<<" "<<right<<endl;
                if(arr[between]==numb){
                    ans = between;
                    break;
                }
                else if(arr[between]>numb)
                    right = between-1;
                else if(arr[between]<numb)
                    left = between+1;
            }
            if(ans!=-1){
                cout<<"Case "<<testCase++<<": "<<between<<"!"<<endl;
            }
            else{
                cout<<"Case "<<testCase++<<": "<<"Not possible."<<endl;
            }

    }
    return 0;
}

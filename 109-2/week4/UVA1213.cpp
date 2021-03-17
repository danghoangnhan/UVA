
#include <bits/stdc++.h>
using namespace std;
long long int sum, num, ans,testCase;
long long int dp[1120+1][14+1]={0};
vector<int> prime;
long long int a[1120+1];

int main()
{
    for (long long int i = 1; i <=1120;i++)
        a[i]=1;
    for(long long int i =2 ;i<=1120;i++){
        if(a[i]){
            prime.push_back(i);
            for(long long int j=i+i;j<=1120;j+=i){
                a[j]=0;
            }
        }
    } 
    
    dp[0][0]=1;
    for(long long int i=0;i<prime.size();i++){
        for(long long int n=1120;n>=prime[i];n--){
            for(long long int k=1;k<=14;k++){
                dp[n][k]=dp[n][k]+dp[n-prime[i]][k-1];
            }
        }
    }
    while ((cin >> sum >> num) && sum != 0 && num != 0){
        cout<<dp[sum][num]<<endl;
    }
    return 0;
}

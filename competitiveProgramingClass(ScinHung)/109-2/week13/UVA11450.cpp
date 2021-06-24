#include <bits/stdc++.h>
using namespace std;
long long int testCase,M,C,K;
#define maxn 10000
vector<int> G[maxn];
bool dp[maxn][maxn];
long long int tmp;
int main(){
    freopen("11450.in", "r", stdin);
    freopen("11450_daniel.out", "w", stdout);
    cin>>testCase;
    while(testCase--){
        cin>>M>>C;
        for(long long int i=0;i<C;i++){
            cin>>K;
            G[i].clear();
            for(long long int j=0;j<K;j++){
                cin>>tmp;
                G[i].push_back(tmp);
            }
        }
        memset(dp,0,sizeof(dp));
        for(long long int i=0;i<G[0].size();i++){
            if(M-G[0][i]>=0){
                dp[M-G[0][i]][0]=true;
            }
        }


        for(long long int i=0;i<C;i++){
            for(long long int j=1;j<M;j++){
                if(dp[j][i-1]){
                    for(long long int k=1;k<G[i].size();k++){
                        if(j-G[i][k]>=0){
                            dp[j-G[i][k]][i]=true;
                        }
                    }
                }
            }
        }
    int x;
    for(x=0;x<=M&&!dp[x][C-1];x++);   
    if(x==M+1)
        cout<<"no solution"<<endl;
    else
        cout<<M-x<<endl;


    }
    return 0;
}
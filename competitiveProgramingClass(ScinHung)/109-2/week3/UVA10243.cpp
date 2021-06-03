#include <bits/stdc++.h>
#define MAXN 10002
using namespace std;
long long int length,connected,index;
vector <int> G[MAXN];
long long int dp[10002][2];
void dfs(int u, int pa){

    dp[u][0]=0;
    dp[u][1]=0;

    for(long long int i =0 ;i<G[u].size();i++){
        int v = G[u][i];
        if(v==pa)continue;
        dfs(u,v);
        dp[u][0]+=dp[v][1];
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
    dp[u][1]++;
}

int main()
{
    while(cin>>length && length){

        for(long long int i = 0 ;i<length;i++)G[i].clear();

        for(long long int i=1;i<length;i++){
            cin>>connected;
            while(connected--){
                cin>>index;
                G[i].push_back(index);
            }
        }
        if(length==1){
            cout<<"1"<<endl;
            continue;
        }
        dfs(1,-1);
        cout<<min(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}
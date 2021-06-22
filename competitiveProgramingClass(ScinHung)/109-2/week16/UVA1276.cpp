#include <bits/stdc++.h>
#define maxn 10000
using namespace std;

long long int testCase;
long long int n,s,k,p[maxn];
vector<int>G[maxn],nodes[maxn];
bool c[maxn];

void dfs1(int u,int f,int dist){
    p[u]=f;
    int nd = G[u].size();
    if(nd==1 &&dist >k){
        nodes[dist].push_back(u);
    }
    for(long long int i=0;i<nd;i++){
        int v = G[u][i];
        if(v!=f){
            dfs1(v,u,dist+1);
        }
    }
}
void dfs2(int u,int f,int d){
    c[u] =true;
    int nd = G[u].size();
    for(long long int i=0;i<nd;i++){
        int v = G[u][i];
        if(v!=f && d<k){
            dfs2(v,u,d+1);
        }
    }
}
long long int solve(){
    int ans=0;
    memset(c,false,sizeof(c));
    for(long long int dist=(n-1);dist>k;dist--){
        for(long long int i=0;i<nodes[dist].size();i++){
            int u = nodes[dist][i];
            if(c[u])
                continue;

            int v = u ;
            for(long long int j=0;j<k;j++){
                v=p[v];
            }
            dfs2(v,-1,0);
            ans++;
        }
    }
    return ans;
}
int main(){

    cin>>testCase;
        for(long long int i=0;i<testCase;i++){
            cin>>n>>s>>k;
            for(long long int i=0;i<=n;i++){
                G[i].clear();
                nodes[i].clear();
            }
            for(long long int i=0;i<n-1;i++){
                int a,b;
                cin>>a>>b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
            dfs1(s,-1,0);
            cout <<solve()<<endl;
        }
    
    return 0;
}
#include <bits/stdc++.h>
#define maxn 10000
using namespace std;

long long int testCase,n,s,k,p[maxn];
vector<int>G[maxn],nodes[maxn];
bool c[maxn];
//p is used to store the intermiated node
void dfs1(int u,int f,int dist){
    p[u]=f;
    if(G[u].size()==1 && dist >k){
        nodes[dist].push_back(u);
        //push back u if u is terminal node and the distance from u to vod is longetr than k 
    }
    for(long long int i=0;i<G[u].size();i++){
        // dfs to the child that store in G, for every time DFS, the dist will be increase
        if(G[u][i]!=f){
            dfs1(G[u][i],u,dist+1);
        }
    }
}
void dfs2(int u,int f,int d){
    c[u] =true;
    for(long long int i=0;i<G[u].size();i++){
        if(G[u][i]!=f && d<k){
            dfs2(G[u][i],u,d+1);
        }
    }
}
long long int solve(){
    int ans=0;
    memset(c,false,sizeof(c));
    for(long long int dist=(n-1);dist>k;dist--){
        for(long long int i=0;i<nodes[dist].size();i++){

            int u = nodes[dist][i];

            if(c[u])continue;

            int v = u ;
            for(long long int j=0;j<k;j++){v=p[v];}

            dfs2(v,-1,0);
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("1276.in", "r", stdin);
    freopen("1276_daniel.out", "w", stdout);
    cin>>testCase;
        for(long long int i=0;i<testCase;i++){
            cin>>n>>s>>k;
             G[i].clear();
            nodes[i].clear();
            for(long long int i=0;i<n-1;i++){
                int a,b;
                cin>>a>>b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
            //find all the client node in the tree
            dfs1(s,-1,0);

            cout <<solve()<<endl;
        }
    
    return 0;
}
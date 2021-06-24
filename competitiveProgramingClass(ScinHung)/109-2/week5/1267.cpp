

#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
vector<long long int> G[maxn];
vector<long long int> Node[maxn];

int B[maxn],V[maxn];
int cnt,maxLevel,t, n, s, k, a, b, next, nextRoot, ans;

void DFS2(int x, int level, int k)
{
    int target;
    if (level <= k){
        for (int i = 0; i < G[x].size(); i++){
            if (G[x].size() == 1 && V[x] == 0){
                V[x] = 1;
                cnt--;
            }
            target = G[x][i];
            DFS2(target, level + 1, k);
        }
    }
}
void DFS1(int x, int level)
{
    int target;
    for (int i = 0; i < G[x].size(); i++){
        if (G[x].size() == 1){                     
            Node[level].push_back(x);
            cnt++;
            if (level > maxLevel)maxLevel = level;
        }
        target = G[x][i];
        if (B[target] > 0)continue;
        B[target] = x;
        DFS1(target, level + 1);
    }
}
int findNext(int start){
    for (int i = start; i > 0; i--)
    {
        if (Node[i].size() > 0){
            for (int j = 0; j < Node[i].size(); j++){
                if (V[Node[i][j]] == 0){
                    maxLevel = i;
                    return Node[i][j];
                }
            }
        }
    }
    return 0;
}

int findP(int x){
    if (x == B[x]){
        return x;
    }
    else{
        return findP(B[x]);
    }
}
int solve(long long int cnt){
    long long int ans =0;
    while (cnt){
        int next = findP(maxLevel);
        if (next != 0){
            nextRoot = findP(next);
        }
        DFS2(nextRoot, 0, k);
    }
    return ans;
}
int main(){

        cin >> t;
        while (t--){
            cin >> n>> s >> k;
            cnt = 0;
            ans = 0;
            maxLevel = 0;
            memset(B, 0, sizeof(B));
            memset(V, 0, sizeof(V));
            B[s] = s;
            V[s] = 1;
            for (int i = 0; i <= n; i++){
                G[i].clear();
                Node[i].clear();
            }
            for (int i = 0; i < n-1; i++)
            {
                cin >> a >> b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
            DFS1(s, 0);
            DFS2(s, 0, k); 
            cout<<"done"<<endl;
            cout << solve(cnt) << endl;
        }
        return 0;
    }
// 1267 Network
// Consider a tree network with n nodes where the internal nodes correspond to servers and the terminal
// nodes correspond to clients. The nodes are numbered from 1 to n. Among the servers, there is an
// original server S which provides VOD (Video On Demand) service. To ensure the quality of service for
// the clients, the distance from each client to the VOD server S should not exceed a certain value k. The
// distance from a node u to a node v in the tree is defined to be the number of edges on the path from u
// to v. If there is a nonempty subset C of clients such that the distance from each u in C to S is greater
// than k , then replicas of the VOD system have to be placed in some servers so that the distance from
// each client to the nearest VOD server (the original VOD system or its replica) is k or less.
// Given a tree network, a server S which has VOD system, and a positive integer k, find the minimum
// number of replicas necessary so that each client is within distance k from the nearest server which has
// the original VOD system or its replica.
// For example, consider the following tree network.

// In the above tree, the set of clients is {1, 6, 7, 8, 9, 10, 11, 13}, the set of servers is {2, 3, 4, 5, 12,
// 14}, and the original VOD server is located at node 12.
// For k = 2, the quality of service is not guaranteed with one VOD server at node 12 because the
// clients in {6, 7, 8, 9, 10} are away from VOD server at distance > k. Therefore, we need one or more
// replicas. When one replica is placed at node 4, the distance from each client to the nearest server of
// {12, 4} is less than or equal to 2. The minimum number of the needed replicas is one for this example.
// Input
// Your program is to read the input from standard input. The input consists of T test cases. The number
// of test cases (T) is given in the first line of the input. The first line of each test case contains an integer
// n (3 ≤ n ≤ 1, 000) which is the number of nodes of the tree network. The next line contains two integers
// s (1 ≤ s ≤ n) and k (k ≥ 1) where s is the VOD server and k is the distance value for ensuring the
// quality of service. In the following n − 1 lines, each line contains a pair of nodes which represent an
// edge of the tree network.
// Output
// Your program is to write to standard output. Print exactly one line for each test case. The line should
// contain an integer that is the minimum number of the needed replicas.

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
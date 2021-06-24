#include <bits/stdc++.h>
#define maxn 1000
#define INF 1e6

using namespace std;
struct Edge{ int from,to,dist;};

struct item{
    int d,u;
    bool operator <(const item& target) const {
        return d>target.d;
    }
};

class dijkstra{
    private:
    int n,m;
    vector<Edge> edges;
    vector<int>G[maxn];
    bool visited[maxn];
    int d[maxn];
    int p[maxn];
    
    public:
    void add_edge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        edges.push_back((Edge){to, from, dist});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int getDistance(int target){return d[target];}
    void run_dijkstra(int s){
        priority_queue<item> pq;
        for (long long int i = 0; i < n; i++){d[i] = INF;}
        d[s] = 0;
        memset(visited,0,sizeof(visited));
        pq.push((item){0,s});
        while(!pq.empty()){
            item x = pq.top();
            pq.pop();
            int u = x.u;

            if(visited[u]){continue;}
            visited[u] = true;

            for(long long int i=0;i<G[u].size();i++){
                    Edge& e = edges[G[u][i]];
                    if(d[e.to]>d[u]+e.dist){
                        d[e.to]= d[u]+e.dist;
                        p[e.to]=u;
                        pq.push((item){d[e.to],e.to});
                    }
            }

        }

    }
};
long long int n,m,currentAmount;
long long int currentFrom,currentTo,currentDist;
long long int queryNumb;
long long int capacity,start,endpoint;

vector<int>fuel;
int main()
{
    while(cin>>n>>m){
        dijkstra myDijkstra = dijkstra();
        fuel.clear();
        for (long long int i = 0; i < n; i++)
        {
            cin >> currentAmount;
            fuel.push_back(currentAmount);
        }
        for (long long int i = 0; i < m; i++)
        {
            cin >> currentFrom >> currentTo >> currentDist;
            myDijkstra.add_edge(currentFrom, currentTo, currentDist);
        }
        cin >> queryNumb;
        for (long long int i = 0; i < queryNumb; i++){
            cin >> capacity >> start >> endpoint;
            myDijkstra.run_dijkstra(start);
            if(myDijkstra.getDistance(endpoint)!=INF){
                cout<<myDijkstra.getDistance(endpoint)<<endl;
            }
            else{
                cout<<"impossible"<<endl;
            }
        }
    }
    return 0;
}

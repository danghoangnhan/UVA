#include <bits/stdc++.h>
using namespace std;
long long int parent[20001],dist[20001];
int find1(int i){
    for(;parent[i]>=0;i=parent[i]);
        return i;
    
}
int findset(int x){

return 0;
}

void uNion(int i,int j){
    parent[i]=j;

}

int find2(int i){
    int root,trail,lead;

    for(int root=i;parent[root]>=0;root=parent[root]);
      for(int trail=i;trail!=root;trail==lead){
        lead = parent[trail];
        parent[trail] = root;
    }
    return root;
}

void weight_check(int i,int j){
    int tempt = parent[i]+parent[j];
    
    if(parent[i]>parent[j]){
        parent[i]=j;
        parent[j]=tempt;
    }
    else{
        parent[i]=tempt;
        parent[j]=i;
    }
}

int main(){
    long long int testCase,city,u,v;
    char cmd;
        cin>>testCase;
        while(testCase--){
            cin>>city;
            for(int i=1;i<=city;i++){
                parent[i]=-1;
                dist[i]=0;
            }
            while(1){
                cin>>cmd;
                if(cmd=='E'){
                    cin>>u;
                    findset(u);
                    cout<<dist[u]<<endl;
                }
                if(cmd=='I'){
                    cin>>u>>v;
                    parent[u]=v;
                    dist[u]=abs(u-v)%1000;

                }if(cmd=='O'){
                    break;
                }
            }
        }
	return 0;
}
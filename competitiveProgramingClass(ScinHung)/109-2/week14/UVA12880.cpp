#include <bits/stdc++.h>
#define maxn 10000+5
using namespace std;
long long int people,interest;
vector<int> G[maxn];
long long int L[maxn];
bool s[maxn];
bool t[maxn];
long long int like,belike;


bool match(long long int n){
    s[n]=true;
    for(long long int i=0;i<G[n].size();i++){
        long long int target = G[n][i];

        if(!t[target]){
            t[target]=true;
            
            if(L[target]==-1||match(L[target])){
                L[target]=n;
                return true;
            }
        }
    }
    return false;
}

long long int KMAlgorithm(){

    long long int ret=0;

    memset(L,-1,sizeof(L));
    memset(s, false, sizeof(s));
    memset(t, false, sizeof(t));
    
    for(long long int i=0;i<people;i++){if(match(i)){ret++;}}
    return ret;
}
int main(){
    freopen("12880.in", "r", stdin);
    freopen("12880_daniel.out", "w", stdout);
    while(cin>>people>>interest){

        for(long long int i=0;i<people;i++){G[i].clear();}

        for(long long int i=0;i<interest;++i){
            cin>>like>>belike;
            G[like].push_back(belike);
        }
        int ans=KMAlgorithm();

        cout<<(ans==people?"YES":"NO")<<endl;
    }
    return 0;

}
#include <bits/stdc++.h>
#define maxn 20+5
#define maxs 100+5
using namespace std;
long long int testCase;

long long int original,plucked,x;
long long int sg[maxn];
long long int ret;
vector<int> nim;
void SG(){
    int mex[maxn]={};
    sg[0]=0;
    for(long long int i=1;i<maxn;i++){

        memset(mex,0,sizeof(mex));

        for(long long int j=0;j<i;j++){

            mex[sg[i]^sg[i-j-1]]=1;

            if(i-j-2>=0){
                mex[sg[i] ^ sg[i - j - 2]] = 1;
            }
        }
        int g=0;
        for(g;mex[g];g++);
        sg[i]=g;
    }

}
int main()
{
    SG();

    freopen("12846.in", "r", stdin);
    freopen("12846_daniel.out", "w", stdout);
    cin>>testCase;
    long long int currentCase=0;
    for(;testCase--;){

        cin>>original>>plucked;
        int used [maxn]={};
        long long int last = 0;
        ret = 0;
        for(long long int j=0;j<plucked;j++){
            cin>>x;
            x--;
            used[last=x]=1;
        }

        nim.clear();

        for(long long int j=0,tmp=0,post;j<original;j++){

            post=(last+j)%original;

            if(used[post]==0){tmp++;}

            if(used[post]||j==original-1){
                if(tmp){
                    nim.push_back(tmp);
                }
                tmp=0;
            }
        }

        

        for(long long int j=0;j<nim.size();j++){ret^=sg[nim[j]];}

        cout<<"Case "<<++currentCase<<": "<<(ret?"yes":"no")<<endl;

    }
    return 0;
}
//it is incompletely
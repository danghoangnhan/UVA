#include <bits/stdc++.h>
using namespace std;

struct student{
    string names;
    int x,y;

    double computeDistance(const student& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    };
};

vector<student>students;
long long int testCase;
long long int Number;
long long int x,y;
string currentName;

int main(){
    freopen("10911.in", "r", stdin);
    freopen("10911_daniel.out", "w", stdout);
    double dp[1<<16];
    double d[16][16];
    long long int currentCase=0;
    while(cin>>Number&&Number){
        Number<<=1;
        for(long long int i=0;i<Number;i++){
            cin>>currentName>>x>>y;
            student currentStudent={
                .names=currentName,
                .x=x,
                .y=y
            };
            students.push_back(currentStudent);
        }
        for(long long int i=0;i<Number;i++){
            for(long long int j=i+1;j<Number;j++){
                d[i][j]=students[i].computeDistance(students[j]);
            }
        }
        d[0][0]=0;
        for(long long int i;i<(1<<Number);i++){
            dp[i]=1e9;
            long long int j;
            for(j=Number-1;j>=0;j--){

                if(j&(i<<1)){break;}

            for(long long int k=0;j<i;j++){
                if(i&(k<<1)){
                    dp[i]=min(dp[i],d[k][j]+dp[i^(1<<j)^(1<<k)]);
                }
            }


            }
        }
        cout<<"Case"<<++currentCase<<dp[1<<Number]-1<<endl;
    }
    return 0;
}

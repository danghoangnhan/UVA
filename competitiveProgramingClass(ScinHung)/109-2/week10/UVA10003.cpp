#include <bits/stdc++.h>
#define  INF 0x3f3f3f3f
#define maxn 10000



using namespace std;
long long int cut[maxn][maxn];
long long int a[maxn];
long long int length;
long long int number;
long long int leftSide,rightSide;

int main(){

    freopen("10003.in", "r", stdin);
    freopen("10003_daniel.out", "w", stdout);

    while(cin>>length&&length!=0){
        cin>>number;
        number++;

        for(long long int i=1;i<number;i++){cin>>a[i];}

        a[0]=0;
        a[number]=length;

        memset(cut,0, sizeof(cut));

        for(long long int i=2;i<=number;i++){
            for(leftSide=0;leftSide<number;leftSide++){

                rightSide=leftSide+i;
                if (rightSide > number)break;

                cut[leftSide][rightSide]=INF;

                for(long long int k = leftSide+1;k<rightSide;k++){
                    cut[leftSide][rightSide] = min(cut[leftSide][rightSide], cut[leftSide][k] + cut[k][rightSide] + a[rightSide] - a[leftSide]);
                }

            }
        }
        cout << "The minimum cutting is "<< cut[0][number] <<"."<< endl;
    } 
    return 0;
}
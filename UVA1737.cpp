#include <bits/stdc++.h>

using namespace std;
long long int testCase,length;
char test[6][3]= {{'a','b','c'},
                {'a','c','b'},
                {'b','a','c'},
                {'b','c','a'},
                {'c','a','b'},
                {'c','b','a'}};
int main()
{


    cin>>length;
    if(length>20000)
        cout<<"TOO LONG"<<endl;
    else if(length==1){
        cout<<"a\n"<<"b\n"<<"c\n"<<endl;
    }
    else{
        for(long long int i=0;i<6;i++){
            for(long long int j=0;j<length;j++){
                cout<<test[i][j%3];
            }
            cout<<endl;
        }
    }
    return 0;
}

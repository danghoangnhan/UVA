#include <bits/stdc++.h>

using namespace std;
long long int arr[100];

long long int number;
int main(){
    arr[1]=1;
    arr[2]=2;
    for(long long int i=3;i<100;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    while(cin>>number&&number){
        cout<<arr[number]<<endl;
    }
    return 0;
}
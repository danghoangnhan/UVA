#include<bits/stdc++.h>
using namespace std;
long long int numb;
vector<int> arr;
int tmp;
long long int ans;
int maxSubArraySum()
{
    long long int max_so_far = INT_MIN;
    long long int max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main(){
    while (cin>>numb&&numb!=0){

        arr.clear();
        for(long long int i=0;i<numb;i++){
            cin>>tmp;
            arr.push_back(tmp);
        }

    ans = maxSubArraySum();
    if(ans >= 0){
        cout <<"The maximum winning streak is "<<ans<<"."<<endl;
         
    }
    else{
        cout<<"Losing streak."<<endl;
    }

    }
    
    return 0;
}
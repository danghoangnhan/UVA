#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int testCase,Number,ans;

	cin>>testCase;

	for(int i=1;i<=testCase;i++){
		cin>>Number;
		long long int arr[Number];

		for(int j=0;j<Number;j++)
			cin>>arr[j];
		
		ans=arr[Number-1]-arr[Number-2];

		for(int j=Number-2;j>=0;j--){
			if(ans<arr[j]-arr[j-1]){
				ans=arr[j]-arr[j-1];
			}
			else if(ans==arr[j]-arr[j-1])
			{
				ans=arr[j]-arr[j-1]+1;
			}
			
		}
		printf("Case %lld: %lld\n",i,ans);

	}
	return 0;
}
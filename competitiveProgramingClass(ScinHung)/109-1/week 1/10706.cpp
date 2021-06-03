#include<bits/stdc++.h>

using namespace std;


int main(){
	unsigned int cas,digit[10000000000],limit = 9,digits=1;

for(unsigned int i=1;i<10000000000;i++){

	if(i>limit){
		limit =limit*10 + 9;
		digits++;
	}

	digit[i]=digits;

}

for(unsigned int i=2;i<10000000000;i++)
	digit[i]=digit[i]+digit[i-1];

for(unsigned int i=2;i<10000000000;i++)
	digit[i]=digit[i]+digit[i-1];


	cin>>cas;

	while(cas-->0){

		long long int numb,i;
		cin>>numb;
		
		for(i=1;numb<digit[i];i++)

		cout<<i-(digit[i]-numb)<<endl;
         

		
	}
	return 0;
}


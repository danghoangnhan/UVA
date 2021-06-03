#include<bits/stdc++.h>

using namespace std;


int main(){
    int cas,numb,student[100000];
	cin >>cas;

	while(cas-->0){
         cin>>numb;
         

         for(long long int i=0;i<numb;i++)
         	scanf("%d",&student[i]);
         
          int ans=student[0]-student[1];
          int MaxAi = student[0];

         for(int i=1;i<numb;i++){
         	ans=max(ans,MaxAi-student[i]);
         	MaxAi=max(student[i],MaxAi);
         }

         printf("%d\n",ans);

	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
const int N=10;
int G[MAXN][MAXN];
int tempans[N],ans[N];
bool flag[MAXN];
string s;
int main()
{
	while(cin>>s)
	{
		if(s[0]=='#')break;
		memset(G,0,sizeof(G));
		memset(flag,0,sizeof(flag));
		bool p=false;
		int u;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				flag[s[i]-'A']=true;
			if(s[i]==':')
			{
				u=s[i-1]-'A';
				p=true;
			}
			else if(p&&s[i]>='A'&&s[i]<='Z')
				G[s[i]-'A'][u]=G[u][s[i]-'A']=1;
		
			else if(s[i]==';'){	p=false;}
		}
 
		int k=0;
		for(int i=0;i<26;i++)
			if(flag[i])
				tempans[k++]=i;
		
		int Min=9;
		do
		{
			int tMin=0;
			for(int i=0;i<k;i++)
			{
				for(int j=i+1;j<k;j++)
				{
					if(G[tempans[i]][tempans[j]])
						tMin=max(tMin,abs(i-j));
				}
				if(tMin>=Min)break;
			}
			if(tMin<Min)
			{
				Min=tMin;
				memcpy(ans,tempans,sizeof(tempans));
			}
		}while(next_permutation(tempans,tempans+k));

		for(int i=0;i<k;i++)
			printf("%c ",ans[i]+'A');

		printf("-> %d\n",Min);
	}
	return 0;
}


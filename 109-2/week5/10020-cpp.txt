#include<iostream>
#include<algorithm>
using namespace std;
struct line {		
	int left,right;
} k[100000],map[100000];		
bool cmp(line a,line b) {
	if(a.left==b.left)	return a.right>b.right;
	else return a.left<b.left;
}
int main() {
	int T,caseno;
	freopen("10020.in","r",stdin); 
	freopen("10020.out","w",stdout);
	cin>>T; caseno=T;
	while(T--) {
		int m;
		cin>>m;
		int l,r,ans=0;
		while(cin>>l>>r) {
			if(l==0&&r==0)	break;
			k[ans].left=l;
			k[ans++].right=r;
		}
		sort(k,k+ans,cmp);	
		line N;	 
		N.left=0;	
		N.right=0;
		int maxr=0,maxl;
		int num=0;
		int flag,i;
		i=0;	
		while(N.left<m) {	
			flag=0;
		    while(i<ans && k[i].left<=N.left) {
				if(k[i].right>N.right&&k[i].right>maxr) {		
					maxr=k[i].right;
					maxl=k[i].left;
					flag=1;
				}
				i++;
			}
			if(flag==0)	break;
			N.left=maxr;	
			N.right=maxr;
			map[num].left=maxl;	
			map[num++].right=maxr;
		}
	    if (T!=caseno-1)cout<<endl;
		if(flag==0)	cout<<"0"<<endl<<endl;
		else {
			cout<<num<<endl;
			for(int i=0; i<num; i++)
				cout<<map[i].left<<" "<<map[i].right<<endl;
		}
	}
}

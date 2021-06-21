#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n,m,l;
int a,b;
 
struct Node {
	char name[20];
	int tot;
}p[N];
 
bool cmp(Node a,Node b) {
	if(a.tot != b.tot) {
		return a.tot < b.tot;
	}else {
		return strcmp(a.name,b.name) < 0;
	}
}
void solve(int id) {
	int cur = n;
	p[id].tot = 0;
	while(cur != m) {
		if(cur / 2 < m) {
			p[id].tot += a;
			cur--;
		}else {
			int tmp = (cur - cur/2)*a; 
			if(b < tmp) {
				p[id].tot += b;
			}else {
				p[id].tot += tmp;
			}
			cur /= 2;
		}
	}
}
void input() {
	char ch;
	for(int i = 0; i < l; i++) {
		int cnt = 0;
		while( (ch = getchar()) != ':') {
			p[i].name[cnt++] = ch;
		}
		p[i].name[cnt] = '\0';
		scanf("%d,%d\n",&a,&b);
		solve(i);
	}
}
 
int main() {
	int t,cas = 1;
	freopen("10670.in","r",stdin); 
    freopen("10670.out","w",stdout); 	
	scanf("%d\n",&t);
	while(t--) {
		scanf("%d%d%d\n",&n,&m,&l);
		input();
		printf("Case %d\n",cas++);
		sort(p,p+l,cmp);
		for(int i = 0; i < l; i++) {
			printf("%s %d\n",p[i].name,p[i].tot);
		}
	}
	return 0;
}

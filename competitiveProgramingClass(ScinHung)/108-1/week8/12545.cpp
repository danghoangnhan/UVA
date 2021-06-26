#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 112;
char s[MAXN], t[MAXN];
int main()
{
	int T, kase = 0;
	freopen("12545.in","r",stdin);
	freopen("12545.out","w",stdout); 
	scanf("%d", &T);
	while(T--) {
		int s1 = 0, t1 = 0, ans1 = 0, ans2 = 0, que = 0;
		scanf("%s%s", s, t);
		for (int i=0;i<strlen(s);i++) {
			if(s[i] == '1') s1++;
			if(t[i] == '1') t1++;
			if(s[i] == '?') que++;
			if(s[i] != t[i] && s[i] == '1') ans1++;
			if(s[i] != t[i] && s[i] == '0') ans2++;
		}
		if(s1 > t1) printf("Case %d: -1\n", ++kase);
		 else printf("Case %d: %d\n", ++kase, que + max(ans1, ans2));
	}
	return 0;
}

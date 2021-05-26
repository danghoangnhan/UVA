#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
const int N = 1000005;
 
int n, m, k, vis[N], g[N];
 
void init() {
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
 
	scanf("%d%d%d", &n, &m, &k);
	g[1] = 1; g[2] = 2; g[3] = 3;
	for (int i = 4; i <= n; i++)
		g[i] = (g[i-1] + g[i-2] + g[i-3]) % m + 1;
}
 
bool solve() {
	int l = 1, r = 1, cnt = 0;
	int ans = n + 1;
	while (r <= n) {
		int t = g[r++];
		vis[t]++;
		if (t <= k && vis[t] == 1) cnt++;
 
		while (l < r && cnt == k) {
			ans = min(ans, r - l);
			t = g[l++];
			vis[t]--;
			if (t <= k && vis[t] == 0) cnt--;
		}
	}
	if (ans <= n) {
		printf("%d\n", ans);
		return false;
	}
	return true;
}
 
int main() {
	int cas;
    freopen("11536.in","r",stdin); 
    freopen("11536.out","w",stdout); 	
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {
		init();
		printf("Case %d: ", i);
		if (solve()) printf("sequence nai\n");
	}
	return 0;
}


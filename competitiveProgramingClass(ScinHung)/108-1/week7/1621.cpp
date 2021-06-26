#include<iostream>
using namespace std;
int n;
int ans[1500 + 10];
int main() {
	int kase;
	freopen("1621.in","r",stdin);
	freopen("1621.out","w",stdout);
	cin >> kase;
	while (kase--) {
		int a, b, c;
		cin >> a >> b >> c;
		int len = 0;
		int pos = 0;
		ans[len++] = 0;
		if (c % 3 == 0) {
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos += 3);
			ans[len++] = ++pos; 
			a--;
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos -= 3);
			ans[len++] = ++pos;
			a--;
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos += 3);
		}
		if (c % 3 == 1) {
			for (int i = 0; i < c / 3 + 1; i++)ans[len++] = (pos += 3);
			ans[len++] = (pos -= 2); b--;
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos -= 3);
			ans[len++] = (pos += 1); a--;
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos += 3);
			ans[len++] = (pos += 2); b--;
		}
		if (c % 3 == 2) {
			for (int i = 0; i < c / 3 + 1; i++)ans[len++] = (pos += 3);
			ans[len++] = (pos -= 1); a--;
			for (int i = 0; i < c / 3; i++)ans[len++] = (pos -= 3);
			ans[len++] = (pos -= 1); a--;
			for (int i = 0; i < c / 3+1; i++)ans[len++] = (pos += 3);
		}
		while (a-- > 1)ans[len++] = ++pos;
		for (int i = 0; i < (b + 1) / 2; i++)ans[len++] = (pos += 2);
		if (b % 2)ans[len++] = --pos;
		else ans[len++] = ++pos;
		for (int i = b & 1; i < (b + 1) / 2; i++)ans[len++] = (pos -= 2);
		for (int i = 0; i < len-1; i++)cout << ans[i]<<" ";
		cout << ans[len - 1] << endl;
	}
	return 0;
}

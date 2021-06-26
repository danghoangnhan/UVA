#include<iostream>
#include<string>
using namespace std;
#define INF 0x3fffffff

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
string t;
int fenzi(int a, int b) {
	int ans = 0; int ans1 = 0;
	for (int i = 2; i < a; i++) {
		ans = ans * 10 + (t[i] - '0');
	}
	ans1 = ans;
	for (int j = a; j <= b; j++) {
		ans = ans * 10 + (t[j] - '0');
	}
	return ans - ans1;
}
int main() {		
	freopen("10555.in", "r", stdin);
    freopen("10555.out","w",stdout);
	while (cin >> t) {
		int ans_fenzi = INF, ans_fenmu = INF;
		if (t == "0")break;
		int len = t.size() - 3;
		for (int i = len - 1; i >= 2; i--) {
			int aa = fenzi(i, len - 1);
			int bb = 0;
			for (int j = i; j <= len - 1; j++) {
				bb = bb * 10 + 9;
			}
			for (int j = 2; j < i; j++) {
				bb *= 10;
			}
			int tmp = gcd(aa, bb);
			aa = aa / tmp;
			bb = bb / tmp;
			if (bb < ans_fenmu) {
				ans_fenzi = aa;
				ans_fenmu = bb;
			}
		}
		cout << ans_fenzi << "/" << ans_fenmu << endl;
	}
}

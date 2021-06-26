#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef pair<int,int> Pair;
#define maxn 10010
int num[maxn];

void change(int l, int r) {
    for(int i = l, j = l + (r - l + 1) / 2; j <= r; j++, i++)
        swap(num[i],num[j]);
}
int main() {
    int test, n;
    freopen("1611.in","r", stdin);
	freopen("1611.out","w", stdout); 
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &n);
        for(int i = 1 ; i <= n; i++)
            scanf("%d", &num[i]);
        vector<pair<int,int> > ans;
        for(int i = 1; i <= n; i++) {
            int pos;
            for(int j = i; j <= n; j++)
                if(num[j] == i) {
                    pos = j;
                    break;
                }
            if(pos == i)
                continue;
            if(i + 2 * (pos - i) - 1 <= n) {
                ans.push_back(Pair(i,i + 2 * (pos - i) - 1));
                change(i, i + 2 * (pos - i) - 1);
            }
            else {
                if((pos - i) % 2) {
                    ans.push_back(Pair(i, pos));
                    change(i,pos);
                }
                else {
                    ans.push_back(Pair(i + 1, pos));
                    change(i + 1, pos);
                }
             i--;
            }
        }
        cout << ans.size() << endl;
        
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d\n",ans[i].first, ans[i].second);
        
	}
    return 0;
}

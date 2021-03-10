#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int L, n, x, r;
    int i, j, k;
    pair<int, int> range[10000];
    freopen("12321.in","r",stdin);
    freopen("12321.out","w",stdout);
    while(scanf("%d %d", &L, &n) == 2 && L) {
        for(i = 0; i < n; i++) {
            scanf("%d %d", &x, &r);
            range[i] = make_pair(x-r, x+r);
        }
        sort(range, range+n);
        int right, left = 0, eliminated = n;
        i = 0;
        while(left < L) {
            right = left;
            while(i < n && range[i].first <= left) {
                if(right < range[i].second)
                    right = range[i].second;
                i++;
            }
            if(right == left) break;
            left = right;
            eliminated--;
        }
        if(left < L)
            puts("-1");
        else
            printf("%d\n", eliminated);
    }
    return 0;
}

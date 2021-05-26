#include <stdio.h>

int gcd(int x, int y) {
    int t;
    while(x%y)
        t = x, x = y, y = t%y;
    return y;
}
int main() {
    int i, j, k;
    int n, m, x;
    freopen("911.in","r",stdin); 
    freopen("911.out","w",stdout); 
    while(scanf("%d %d", &n, &m) == 2) {
        int A[305], sum = 0;
        for(i = 1; i <= n; i++)
            A[i] = i;
        while(m--) {
            scanf("%d", &x);
            sum += x;
            for(i = 2; i <= x; i++) {
                j = i;
                for(k = 2; k <= n; k++) {
                    int g = gcd(A[k], j);
                    if (g==1) continue;
                    A[k] /= g;
                    j /= g;
                    if (j==1) break;
                }
            }
        }
        long long ret = 1;
        if(sum != n) {ret = 0;}
        else {
            for(i = 1; i <= n; i++)
                ret *= A[i];
        }
        printf("%lld\n", ret);
    }
    return 0;
}

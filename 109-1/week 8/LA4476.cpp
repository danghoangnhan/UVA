#include <bits/stdc++.h>
long long bill(long long energy) {
    long long consume = 0;
    if(energy <= 100)return consume + energy*2;
    consume += 100*2;
    if(energy <= 10000)return consume + (energy-100)*3;
    consume += (10000-100)*3;
    if(energy <= 1000000)return consume + (energy-10000)*5;
    consume += (1000000-10000)*5;
    return consume + (energy-1000000)*7;
}
int main() {
    long long A, B;
    while(scanf("%lld %lld", &A, &B) == 2) {
        if(A+B == 0)    break;
        long long l = 0, r = A, m;
        long long total, tmp, X, Y;
        
        while(l <= r) {
            m = (l+r)/2;
            tmp = bill(m);
            if(tmp == A) {
                total = m;
                break;
            }
            if(tmp > A)
                r = m-1;
            else
                l = m+1;
        }
        l = 0, r = total;
        while(l <= r) {
            m = (l+r)/2;
            X = bill(m), Y = bill(total-m);
            if(Y-X == B) {
                printf("%lld\n", X);
                break;
            }
            if(X > Y || Y-X < B)
                r = m-1;
            else
                l = m+1;
        }
    }
    return 0;
}

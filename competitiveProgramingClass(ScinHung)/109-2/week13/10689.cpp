#include <bits/stdc++.h>

using namespace std;

struct matrix
{
    long long cell[2][2];
    matrix(long long a = 0, long long b = 0, long long c = 0, long long d = 0)
    {
        cell[0][0] = a, cell[0][1] = b, cell[1][0] = c, cell[1][1] = d;
    }
} one(1, 1, 1, 0);

int mod;

matrix multiply(const matrix &a, const matrix &b)
{
    matrix r;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r.cell[i][j] = (a.cell[i][0] * b.cell[0][j] + a.cell[i][1] * b.cell[1][j]) % mod;
    return r;
}

matrix matrixPow(long long k)
{
    if (k == 1) return one;
    matrix r = matrixPow(k >> 1);
    r = multiply(r, r);
    if (k & 1) r = multiply(r, one);
    return r;
}

int main(int argc, char *argv[])
{
    int cases, a, b, n, m;
    freopen("10689.in","r",stdin); 
    freopen("10689.out","w",stdout); 	    
    cin >> cases;
    while (cases--)
    {
        cin >> a >> b >> n >> m;
        mod = pow(10, m);
        if (n == 0) cout << a % mod << '\n';
        else if (n == 1) cout << b % mod << '\n';
        else
        {
            matrix r = matrixPow(n - 1);
            cout << (r.cell[0][0] * b + r.cell[0][1] * a) % mod << '\n';
        }
    }

    return 0;
}

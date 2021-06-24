#include <bits/stdc++.h>

int main()
{
    long long int x, k, T;
    freopen("10673.in", "r", stdin);
    freopen("10673_daniel.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        cin>>x>>k;
        cout<<x - x % k<<x % k<<endl;
    }
    return 0;
}

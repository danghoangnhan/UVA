#include <iostream>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
const int N = 10000;
int a[N];
 
int main()
{
    int n, m;
    freopen("11057.in", "r", stdin);
    freopen("11057.out", "w", stdout);
    while(~scanf("%d", &n)) {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);

        sort(a, a+n);
 
        int low=0, high=n-1, pi, pj;
        while(low < high) {
            if(a[low] + a[high] < m)
                low++;
            else if(a[low] + a[high] == m) {
                pi = low++;
                pj = high--;
            } else
                high--;
        }
 
        printf("Peter should buy books whose prices are %d and %d.\n\n", a[pi], a[pj]);
 
    }
 
    return 0;
}

#include<iostream> 
using namespace std; 
const int maxn = 505;
int n;
int a[maxn];
int main()
{
    freopen("1620.in", "r", stdin);
    freopen("1620.out", "w",stdout);
    int t;
    cin >> t;
    while (t--) {
         cin >> n;
         for (int i = 0; i < n; i++) cin >> a[i];
         int cnt = 0;
         for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++)
                 if (a[i]>a[j])    cnt++;
         }
         if (cnt % 2 && n % 2)   cout << "impossible" << endl;
          else cout << "possible" << endl;
     }
     return 0;
 }

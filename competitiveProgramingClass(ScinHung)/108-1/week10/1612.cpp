#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int UP = 16384 + 5;
int R[UP], S[UP][3];
 
int get(int cur, int a, int b, int c, bool j){
     int v[8] = {0, a, b, c, a+b, a+c, b+c, a+b+c};
     sort(v, v + 8);
     for(int i = 7; i >= 0; i--)
         if(v[i] < cur || (j && v[i] == cur)) return v[i];
     return -1;
}
int main(){
    int n, cases = 0;
    freopen("1612.in","r",stdin);
    freopen("1612.out","w",stdout);
    while(scanf("%d", &n) && n){
       for(int i = 1; i <= n; i++){
          for(int t = 0; t < 3; t++){
             double x;
             scanf("%lf", &x);
             S[i][t] = round(x * 100); //先乘以100再用round函數(四捨五入) 
           }
        }
       for(int i = 1; i <= n; i++) scanf("%d", &R[i]);
       int ans = S[R[1]][0] + S[R[1]][1] + S[R[1]][2];
       for(int i = 2; i <= n && ans >= 0; i++)
          ans = get(ans, S[R[i]][0], S[R[i]][1], S[R[i]][2], R[i-1] < R[i]);
       if(ans < 0) printf("Case %d: No solution\n", ++cases);
          else printf("Case %d: %.2f\n", ++cases, ans / 100.0); //最後再除以100回來
    }
    return 0;
 }

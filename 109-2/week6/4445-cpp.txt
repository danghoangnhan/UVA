#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int i, n, caseNo = 1, order[8];
double a[8], b[8], L, maxL;
double greedyLanding() { 
  double lastLanding = a[order[0]]; 
  for (i = 1; i < n; i++) { 
     double targetLandingTime = lastLanding + L;
     if (targetLandingTime <= b[order[i]])
        lastLanding = max(a[order[i]], targetLandingTime);
      else
        return 1;
  }
  return lastLanding - b[order[n - 1]];
 }
 
int main() {
 freopen("4445.in","r",stdin); 
 freopen("4445.out","w",stdout); 
 while (scanf("%d", &n), n) { // 2 <= n <= 8
   for (i = 0; i < n; i++) { 
    scanf("%lf %lf", &a[i], &b[i]);
    a[i] *= 60; b[i] *= 60; 
    order[i] = i;
   }
   maxL = -1.0; 
   do { 
     double lo = 0, hi = 86400; 
     L = -1; 
     while (fabs(lo - hi) >= 1e-3) { 
       L = (lo + hi) / 2.0; 
       double retVal = greedyLanding(); 
       if (retVal <= 1e-2) lo = L; 
         else hi = L; 
     }
     maxL = max(maxL, L); 
   } while (next_permutation(order, order + n)); 
   maxL = (int)(maxL + 0.5); 
   printf("Case %d: %d:%0.2d\n", caseNo++, (int)(maxL/60), (int)maxL%60);
 }
 return 0;
}

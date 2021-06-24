#include <bits/stdc++.h>
 using namespace std;
long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    long long g = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
long long n, c1, c2, n1, n2;
long long x, y;
long long int upLimit,downLimit;

int main() {
	freopen("10090.in","r",stdin); 
  freopen("10090_daniel.out","w",stdout); 	

    while (cin>>n&&n>0) {

       cin>>c1>>n1>>c2>>n2;

       long long g = extend_gcd(n1, n2, x, y);

       downLimit = -1*ceil(1.0 * n* x / n2);

       upLimit  = floor(1.0 * n * y / n1);


       if (downLimit > upLimit || n % g) {
         cout<<"failed"<<endl;;
         continue;
       }

       if (c1 * n2 < c2 * n1) {
          x = n * x / g + n2 / g * upLimit;
          y = n * y / g - n1 / g * upLimit;
       }
      else {
          x = n * x / g + n2 / g * downLimit;
          y = n * y / g - n1 / g * downLimit;
      }
       cout<<x<<" "<<y<<endl;
    }
    return 0;
}

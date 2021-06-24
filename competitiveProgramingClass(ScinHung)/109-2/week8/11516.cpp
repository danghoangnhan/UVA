#include <cstdio>
#include <algorithm>
using namespace std;
 
int Ap, house;
int houseNo[100000+10];
 
bool greedycheck(int mid){

    int used = 1;
    int wifirange = houseNo[0] + mid;
    for ( int i = 0; i < house; i++ ) {

        if ( houseNo[i] > wifirange ) {
             wifirange = houseNo[i] + mid; used++; 
        }
    } 
    return used <= Ap;
}
 
int main ()
{
    int testCase;
    freopen("11516.in","r",stdin); 
    freopen("11516.out","w",stdout); 
    scanf ("%d", &testCase);
    while ( testCase-- ) {
        scanf ("%d %d", &Ap, &house);

        for ( int i = 0; i < house; i++ ) scanf ("%d", &houseNo[i]); 

        if ( Ap >= house ) {
             printf ("0.0\n"); 
             continue; 
        }

        sort (houseNo, houseNo + house);

        int lo = 0;
        int hi = 2*(houseNo[house-1]-houseNo[0])+1;

        while ( hi - lo > 1 ) {
            int mid = (lo + hi) / 2;
            if ( greedycheck(mid * 2) ) hi = mid;
            else lo = mid;
        }

        lo *= 10;
        hi *= 10; 

        for ( int i = 0; i < house; i++ ) houseNo[i] *= 10;
        
        while ( hi - lo > 1 ) {
            int mid = (lo + hi) / 2;
            if ( greedycheck(mid * 2) ) hi = mid;
            else lo = mid;
        } 
        printf ("%d.%d\n", hi / 10, hi % 10); 
    } 
    return 0;
}

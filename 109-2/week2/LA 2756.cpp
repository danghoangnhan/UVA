#include<iostream> 
using namespace std;  
  
int main()  
{  
    int T,n,m; 
	// freopen("2756.in","r",stdin); 
	// freopen("2756.out","w",stdout);
	scanf("%d",&T); 
    while(T--)  
    {  
		scanf("%d",&n);   
        m = (n % 2 == 0) ? (n / 2) * (n / 2 - 1) : (n - 1) * (n - 1) / 4;
        printf("%d\n", m);
    }  
    return 0;
}  

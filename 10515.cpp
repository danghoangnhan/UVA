#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
int digit[10][4] = {
	0,0,0,0,
	1,1,1,1,
	6,2,4,8,
	1,3,9,7,
	6,4,6,4,
	5,5,5,5,
	6,6,6,6,
	1,7,9,3,
	6,8,4,2,
	1,9,1,9};
 
int main () 
{
	char m[104],n[104];
    while (scanf("%s%s",m,n) && (strcmp(m,"0")||strcmp(n,"0")) ) {
		if ( !strcmp(n, "0") ) {
			printf("1\n");
			continue;
		}
		int nvalue = n[strlen(n)-1]-'0';
		if ( strlen(n) > 1 )
			nvalue += (n[strlen(n)-2]-'0')*10;
		printf("%d\n",digit[m[strlen(m)-1]-'0'][nvalue%4]);
	}
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[10010][4] = {"abc","acb","bac","bca","cab","cba"};
    int n,i,j;
    scanf("%d",&n);
    if(n == 1) printf("a\nb\nc\n");
    else if(n*6 > 100000) printf("TOO LONG\n");
    else {  for(i=0;i<6;i++) {
              for(j=0;j<n;j++) { printf("%c",a[i][j%3]);}
              printf("\n");
            }  
         }
    return 0;
}

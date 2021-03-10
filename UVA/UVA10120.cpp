#include <iostream>

using namespace std;
    long long int number,gift,ans;
long long int dfs(long long int cur,long long int len ){
        if (cur <= 0 || cur > number)
        return 0;
    if (cur == gift)
        return 1;
    if (dfs(cur + len, len + 2))
        return 1;
    if (dfs(cur - len, len + 2))
        return 1;
    return 0;
}
int main()
{

    while(scanf("%lld%lld",&number,&gift)&&(number!=0||gift!=0)){

                if(number>=49){
                     printf("Let me try!\n");
                }

                else if(dfs(1,3))
                    printf("Let me try!\n");
                else
                    printf("Don't make fun of me!\n");
    }
    return 0;
}

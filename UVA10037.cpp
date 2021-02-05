#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("10037.in","r",stdin);
    freopen("10037.out","w",stdout);
    int Case,N,P[1001],i;
    scanf("%d",&Case);
    while (Case--)
    {
        scanf("%d",&N);
        for (i=0; i<N; i++) scanf("%d",&P[i]);
        sort (P,P+N);

        int time=0;

        for (i=N-1; i>=3; i-=2){               //三個人以上
            int A = P[1]+P[0]+P[i]+P[1];
            int B = P[i]+P[0]+P[i-1]+P[0];
            if (A<B) time += A;
            else time += B;
        }
        if (i == 2) time += (P[1]+P[0]+P[2]);   //三個人
        else if (i == 1) time += P[1];          //兩個人
        else if (i == 0) time += P[0];          //一個人

        printf("%d\n",time);

        for (i=N-1; i>=3; i-=2){
            int A = P[1]+P[0]+P[i]+P[1];
            int B = P[i]+P[0]+P[i-1]+P[0];
            if (A<B) printf("%d %d\n%d\n%d %d\n%d\n",P[0],P[1],P[0],P[i-1],P[i],P[1]);
            else printf("%d %d\n%d\n%d %d\n%d\n",P[0],P[i-1],P[0],P[0],P[i],P[0]);
        }
        if (i == 2) printf("%d %d\n%d\n%d %d\n",P[0],P[1],P[0],P[0],P[2]);
        else if (i == 1) printf("%d %d\n",P[0],P[1]);
        else if (i == 0) printf("%d\n",P[0]);

        if (Case) printf("\n");
    }
    return 0;
}

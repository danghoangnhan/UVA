#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double const epx = 1e-8;
int dcmp( double x)
{
    if( fabs(x) < epx)
        return 0;
    return x < 0 ?-1:1;
}
struct node
{
    double x,y,d;
    node(double a,double b):x(a),y(b){}
    node(){}
};
typedef node vec;

vec operator - ( node a,node b)
{
    return vec( a.x-b.x,a.y-b.y);
}
node point[ 110 ];

double length( node a,node b)
{
    vec A = a - b;
    return sqrt(A.x*A.x + A.y*A.y);
}
// ab*ac 外積 
double crosspruduct(node a,node b,node c)
{
    vec AB = b - a;
    vec AC = c - a;
    return AB.x * AC.y - AB.y * AC.x ;
}
//座標排序
bool idcmp(node a ,node b)
{
    return ( a.x == b.x )? ( a.y < b.y ): ( a.x < b.x );
}

//以p[0]為convex hull起點,與剩下的點行極角排序
bool anglecmp( node a,node b)
{
    double cp = crosspruduct( point[0],a,b);
    if( dcmp(cp) == 0 )
       return  a.d < b.d;  //極角相等距離由近到遠 
    return cp > 0;         //極角排序: p[0], a,b逆時針方向 
}

double graham( int n)
{
    if( n > 1 )
    {
        sort( point,point+n,idcmp);  //座標排序
        for(int i=1; i<n; i++)
            point[i].d = length(point[0],point[i]); //p[i]點與p[0]距離 

        sort(point+1,point+n,anglecmp); //極角排序
    }
    int top = n-1;  // 暫時值 
    if( n > 2 )     //graham's scan 至少3點 
    {
        top = 1;
        for( int i = 2;i <n ;++i)
        {
            while( top > 0
                  &&crosspruduct( point[ top-1],point[top],point[i])<0)
                    --top;
            point[++top] = point[i];
        }
    }
    point[++top] = point[0]; // 封閉起來 

    double sum = 0.0;
    for(int i=0; i<top; i++) 
    {
        sum += length( point[i],point[i+1]);
    }

    return sum ;

}

int main()
{
    int cas,len,num;
    freopen("11096.in", "r", stdin);
    freopen("11096.out", "w", stdout);    
    cin>>cas;
    while( cas-- )
    {
        cin>>len>>num;
        for(int i=0; i<num; i++)
        {
            scanf("%lf %lf",&point[i].x,&point[i].y);
        }

        double ans = graham(num);
        if( ans < len )
            ans = (double)len ;
        printf("%.5lf \n",ans);

    }

    return 0;
}

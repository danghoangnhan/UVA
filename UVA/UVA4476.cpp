#include<bits/stdc++.h>

using namespace std;


long long int bill(long long int m){
    long long int ans = 0;
    if(m<=100)
        return ans +m*2;
    ans+=100*2;
    if(m<=10000)
        return ans + (m-100)*3;
    ans+=(10000-100)*3;
    if(m<=1000000)
        return ans + (m-10000)*5;
    ans+=(1000000-10000)*5;
    return ans + (m -1000000)*7;
}

int main()
{

    long long int a=0,b=0,ans,tmp,l,r,m;
    while(cin>>a>>b){
            if(a==0&&b==0)
             break;

        l=0;
        r=a;
        while(l<=r){
            m=(l+r)/2;
            tmp=bill(m);
            if(tmp==a){
                ans=m;
                break;
            }
            if(tmp>a){
                r=m-1;

            }
            else{
                l=m+1;
            }
        }
        //cout<<ans<<endl;
        l=0,r=ans;
        while(l<=r){
            m =(l+r)/2;
            long long int billx=bill(m);
            long long int billy=bill(ans-m);

            if(billy-billx==b){
                printf("%lld\n",billx);
                break;
            }
            if(billx>billy||billy-billx<b){
                r=m-1;

            }
            else{
                l=m+1;
            }
        }


    }
    return 0;
}

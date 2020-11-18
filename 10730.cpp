#include <bits\stdc++.h>

using namespace std;
long long int tmp;
int main()
{
    long long int number;
    while(scanf("%lld",&number)&&number){
            long long int arr[number];
            char c;
            int ans=1;
            //scanf("%c",&c);
            cin>>c;

            for(long long int i=0;i<number;i++){
                long long int tmp;
                 scanf("%lld",&tmp);
                 arr[tmp]=i;
            }
            for(long long int i=0;i<number;i++){
                for(long long int j=number-1;j>=0;j--){
                    if(arr[j] > arr[i])continue;
                    int r = i*2-j;
                    if(r<0)continue;
                    if(r>=number) break;
                    if(arr[r]> arr[i]){
                        ans=0;
                        break;
                    }
                }
                //if(ans==1)break;
            }

            if(ans)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;







    }

    return 0;
}

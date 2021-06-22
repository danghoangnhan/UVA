#include <bits/stdc++.h>


using namespace std;
long long int testCase, k, n, s, d;
long double x, y;
long long int ret;
vector<pair<int, int>> enemy;
vector<pair<int, int>> sniper;

bool sortingY(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

bool check(long long int x)
{
    for (long long int i = 0; i <n; i++){
        
        if (enemy[i].second - k + x > d)return false;

        cout << "done" << endl;
        double t = double(enemy[i].second - k + x);
        double delta = sqrt((double)(d * d - t * t));

        pair<int, int> newSniper = make_pair(enemy[i].first - (long long int)delta, enemy[i].first + (long long int)delta);
        sniper.push_back(newSniper);

        cout<<sniper[i].first<<" "<<sniper[i].second<<endl;
    }
    //cout << "done" << endl;
    sort(enemy.begin(), enemy.end(), sortingY);
    int cnt = 1;
    long long int R = sniper[0].second;
    
    for (long long int i = 1; i < n; i++)
    {
        if (sniper[i].first > R)
        {
            cnt++;
            R = sniper[i].second;                
        }
       
    }
    cout << cnt << endl;
    return (cnt > s ? false : true);
    }
    int main(){
        freopen("12255.in", "r", stdin);
        freopen("12255_daniel.out", "w", stdout);
        cin >> testCase;
        for (long long int currentCase = 1; currentCase <= testCase; currentCase++)
        {
            cin >> k >> n >> s >> d;

            sniper.clear();
            enemy.clear();

            long long int left = 0;
            long long int right = d;

            for (long long int i = 0; i < n; i++)
            {
                cin >> x >> y;
                sniper.push_back(make_pair(x, y));
                //cout<<sniper[i].first<<" "<<sniper[i].second<<endl;
            }
            
            while (left <= right){

                long long int mid = (left + right) / 2;
                //cout << left << " " << right << " " << mid << endl;
                if (check(mid)){

                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
                cout<<left<< " "<<right<<endl;
            }
            cout<<"Case"<<currentCase<<": ";
            if(right<0){
                cout<<"IMPOSSIBLE"<<endl;
            }else{
                cout<<right<<endl;
            }
        }
        return 0;
    }
   

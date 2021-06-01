#include <bits/stdc++.h>
long long int testCase, k, n, s, d;
using namespace std;
long double x, y;
long long int ret;
vector<pair<int, int>> enemy;
vector<pair<int, int>> sniper;

bool sortingX(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
bool sortingY(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

bool check(long long int x)
{
    for (long long int i = 0; i < n; i++){
        if (enemy[i].second - k + x > d)return false;

        double t = double(enemy[i].second - k + x);
        double delta = sqrt((double)d * d - t * t);
        sniper.push_back(make_pair(enemy[i].first - (long long int)delta, enemy[i].first + (long long int)delta));
    }
    sort(enemy.begin(), enemy.end(), sortingY);
    int cnt = 1;
    long long int R = sniper[1].second;

    for (long long int i = 1; i <= n; i++)
    {
        if (sniper[i].first > R)
        {
            {
                cnt++;
                R = sniper[i].second;
            }
        }
       
    }
    if (cnt > s)
        return false;
    else
        return true;
}
    int main(){
        cin >> testCase;

        for (long long int k = 1; k <= testCase; k++)
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
            }
            sort(enemy.begin(), enemy.end(), sortingX);
            //for (long long int i = 0; i < v.size(); i++){cout << v[i].first << " " << v[i].second << endl;}
            printf("Case %d: ", k);
            if (check(0) == 0)
            {
                cout << "IMPOSSIBLE" << endl;
                continue;
            }
            while (left <= right){
                long long int mid = (left + right) / 2;
                if (check(mid))
                {
                    left = mid + 1;
                    ret = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            printf("%lld\n", ret);
        }
        return 0;
    }
   

#include <bits/stdc++.h>
using namespace std;

long long int n, m, s, v;
double one, two;
long long int run;
double distanceLog[101][101];
long long int cnt;
long long int allocateHole[101];
long long int allocateRat[101];
vector<pair<int, int>> rat, hole;

double distance(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int check()
{
    long long int ans = 0;
    for (long long int i = 0; i < m; i++)
    {
        ans += (allocateHole[i] >= 0 ? 1 : 0);
    }
    return (ans >= n ? 1 : 0);
}

int solve(long long int ratNumb, long long int holeNumb)
{
    printf("runt at ratNumb %lld and holeNumb %lld\n", ratNumb, holeNumb);

    if(allocateHole[holeNumb] ==ratNumb){
        solve(ratNumb+1, 0);
    }
    while (holeNumb < hole.size())
    {
        if (distanceLog[ratNumb][holeNumb] <= run)
        {
            printf(" found hole %lld \n", holeNumb);
            break;
        }
    }
    if (holeNumb == hole.size())
    {
        printf("out of hole,checking......\n");
        return (cnt>=n ?1:0);
    }
    else if (allocateHole[holeNumb] >= 0)
    {
        printf("hole %lld is allocated by the %lld rat\n", holeNumb, allocateHole[holeNumb]);
        long long int prev = allocateHole[holeNumb];
        allocateHole[holeNumb]=ratNumb;
        return solve(prev, holeNumb + 1);
    }
    else if (holeNumb < hole.size() )
    {
        printf(" rat %lld allocated the %lld hole\n", ratNumb, holeNumb);
        allocateHole[holeNumb] = ratNumb;
        cnt++;
        if (ratNumb >= rat.size() - 1)
        {
            if(cnt==n){
            
            }
        }
        else
        {
            printf("run next rat\n");
            if(cnt==n){
                return 1;
            }
            else{
                return solve(ratNumb + 1, 0);
            }
           
        }
    }
    return check();
}
int main()
{
    cnt=0;
    cin >> n >> m >> s >> v;
    run = s * v;

    memset(allocateHole, -1, sizeof(allocateHole));
    memset(allocateRat, 0, sizeof(allocateRat));

    // for(long long int i=0;i<=m;i++){
    //     cout<<allocate[i]<<endl;
    // }
    for (long long int i = 0; i < n; i++)
    {
        cin >> one >> two;
        rat.push_back(make_pair(one, two));
    }
    for (long long int i = 0; i < m; i++)
    {
        cin >> one >> two;
        hole.push_back(make_pair(one, two));
    }
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            distanceLog[i][j] = distance(rat[i].first, rat[j].second, hole[j].first, hole[j].second);
        }
    }
    cout << solve(0, 0) << endl;
    return 0;
}
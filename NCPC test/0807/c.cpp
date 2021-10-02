#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N, X;
    cin >> N >> X;

    if (N == X)
        cout << 10 << endl;
    else
    {
        vector<int> C[11];
        for (int i = 2; i <= 10; i++)
        {
            long long int tmp = N;
            while (tmp > 1)
            {
                int s = tmp % i;
                tmp /= i;
                C[i].push_back(s);
            }
            if (tmp)
                C[i].push_back(tmp);
        }

        int ans = 0;
        for (int j = 2; j <= 10; j++)
        {
            long long int cp = 0;
            cout << j << "-out:" << endl;
            cout << C[j][0] << endl;
            for (int k = 0; k < C[j].size(); k++)
            {
                cout << C[j][k] << " ";
                cp += (C[j][k] * pow(10, k));
            }
            cout << endl;
            cout << j << "--" << cp << endl;
            if (cp == X)
            {
                ans = j;
                break;
            }
        }

        cout << ans << endl;
    }
}
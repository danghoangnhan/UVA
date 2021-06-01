#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
long long int fileNumber;
vector<string> listString;
string tmp;
long long int row, column;
long long int maxFileLength;
long long int tmpInt;
long long int maxRowLength;
long long int cnt;
long long int flag;
long long int last;
int main()
{
    while (cin >> fileNumber)
    {

        maxFileLength = 0;
        listString.clear();

        for (long long int i = 0; i < fileNumber; i++)
        {
            cin >> tmp;
            listString.push_back(tmp);
            maxFileLength = max(maxFileLength, (long long int)tmp.length());
        }
        sort(listString.begin(), listString.end());
        maxRowLength = maxFileLength;
        column = 1;
        row = 1;
        //cout<<maxRowLength<<endl;
        tmpInt = maxRowLength;
        while (maxRowLength + 2 + maxFileLength < 60)
        {
            maxRowLength += (maxFileLength + 2);
            column++;
        }

        row = fileNumber / column;
        flag = maxRowLength;
        if (fileNumber % column > 0)
        {
            row++;
            flag = fileNumber % column;
        }
        for (long long int i = 0; i < 60; i++)
        {
            printf("%c", '-');
        }
        cout << endl;
        for (long long int j = 0; j < row; j++)
        {
            for (long long int cnt = 0, k = j; k < listString.size(); k += row, cnt++)
            {

                if (j == row - 1 && flag == cnt + 1)
                {
                    cout.width(maxFileLength + 2);
                    cout << left << listString[k] << endl;
                }
                else if (cnt == column - 1)
                {
                    cout.width(maxFileLength);
                    cout << left << listString[k] << endl;
                }
                else
                {
                    cout.width(maxFileLength + 2);
                    cout << left << listString[k];
                }
            }
        }
    }
    return 0;
}
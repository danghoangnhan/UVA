#include <bits/stdc++.h>
using namespace std;
long long int testCase;
long long int N, M, L;
long long int inputA,inputB;
char buf[20];
string input;
struct company{

    string companyName;
    long long int A,B;
    long long int ans;
    bool operator<(const company &other) const
    {
        return ans < other.ans;
    }
};

vector <company> node;
long long int solve(long long int currentAmount,long long int A,long long int B){
    if (currentAmount == M)
        return 0;
    if (currentAmount / 2 >= M){
        int cost = min((currentAmount - currentAmount / 2) * A,B);

        return solve(currentAmount / 2, A, B) + cost;
    }
    return solve(currentAmount - 1, A, B) + A;
}
int main(){
    cin>>testCase;
    for(long long int i=1;i<=testCase; i++){
        cout << "Case " <<i<< endl;
        cin>>N >>M>>L;
        node.clear();
        for(long long int j=0;j<L;j++){

            scanf(" %[^:]:%d,%d",&buf,&inputA,&inputB);
            struct company input = {
                .companyName = string(buf),
                .A = inputA,
                .B = inputB,
                .ans = solve(N, inputA, inputB)};
            node.push_back(input);
        }

        sort(node.begin(), node.begin() + L);
        for(long long int j=0;j<L;j++){
            cout<<node[j].companyName<<" "<<node[j].ans<<endl;
        }
    }
    return 0;
    }

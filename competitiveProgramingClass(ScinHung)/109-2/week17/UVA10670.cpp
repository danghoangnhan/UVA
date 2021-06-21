#include <bits/stdc++.h>
using namespace std;
long long int testCase,N, M, L,inputA,inputB;
char buf[1000];
string input;
struct company{

    string companyName;
    long long int A,B,ans;
    bool operator<(const company& other) const{
        if(ans!=other.ans){
            return ans < other.ans;
        }
        else{
            return companyName.compare(other.companyName)<0;
        }
    }
};
vector<company> companyList;
long long int solve(long long int currentAmount,long long int A,long long int B){

    if (currentAmount == M)return 0;

    if (currentAmount / 2 >= M){
        int cost = min((currentAmount - currentAmount / 2) * A,B);
        return solve(currentAmount / 2, A, B) + cost;
    }
    return (currentAmount - M) * A;
}
int main(){
    freopen("10670.in", "r", stdin);
    freopen("10670_daniel.out", "w", stdout);
    cin>>testCase;
    for(long long int i=1;i<=testCase; i++){
        cout << "Case " <<i<< endl;
        cin>>N >>M>>L;
        companyList.clear();
        for(long long int j=0;j<L;j++){
            scanf(" %[^:]:%d,%d",buf,&inputA,&inputB);
            company currentCompany = {
                .companyName = string(buf),
                .A = inputA,
                .B = inputB,
                .ans = solve(N, inputA, inputB)
            };
            companyList.push_back(currentCompany);
        }
        sort(companyList.begin(),companyList.end());
        for(long long int j=0;j<companyList.size();j++){
            cout<<companyList[j].companyName<<" "<<companyList[j].ans<<endl;
        }
    }
    return 0;
    }

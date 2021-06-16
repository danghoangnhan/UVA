// 10090 Marbles
// I have some (say, n) marbles (small glass balls) and I am going to buy some boxes to store them. The
// boxes are of two types:
// Type 1: each box costs c1 Taka and can hold exactly n1 marbles
// Type 2: each box costs c2 Taka and can hold exactly n2 marbles
// I want each of the used boxes to be filled to its capacity and also to minimize the total cost of buying
// them. Since I find it difficult for me to figure out how to distribute my marbles among the boxes, I
// seek your help. I want your program to be efficient also.
// Input
// The input file may contain multiple test cases. Each test case begins with a line containing the integer
// n (1 ≤ n ≤ 2, 000, 000, 000). The second line contains c1 and n1, and the third line contains c2 and n2.
// Here, c1, c2, n1 and n2 are all positive integers having values smaller than 2,000,000,000.
// A test case containing a zero for n in the first line terminates the input.
// Output
// For each test case in the input print a line containing the minimum cost solution (two nonnegative
// integers m1 and m2, where mi = number of Typei boxes required) if one exists, print ‘failed’ otherwise.
// If a solution exists, you may assume that it is unique.
// Sample Input
// 43
// 1 3
// 2 4
// 40
// 5 9
// 5 12
// 0
// Sample Output
// 13 1
// failed

#include <bits/stdc++.h>

long long int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b)
    {
        d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    }
    else
        x = 1, y = 0;
    return d;
} // ax+by=1 ax同餘 1 mod b

long long int testCase;
long long int c1, c2, n1, n2;
using namespace std;
int main(){
    while(cin>>testCase&&testCase!=0){
        cin>>c1>>c2>>n1>>n2;
    }
    return 0;
}



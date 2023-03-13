#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 재귀
int Fibonacci_Recursion(int n)
{
    if (n < 2)
        return n;

    return Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2);
}

// 메모이제이션(하향식 접근법)
int Fibonacci_Memoization(int n)
{
    const int UNKNOWN = 0;
    static unordered_map<int, int> memo;

    if (n < 2)
        return n;

    if (memo[n] != UNKNOWN)
        return memo[n];

    int result = Fibonacci_Memoization(n - 1) + Fibonacci_Memoization(n - 2);
    memo[n] = result;

    return result;
}

// 타뷸레이션(상향식 접근법)
int Fibonacci_Tabulation(int n)
{
    vector<int> DP(n + 1, 0);
    DP[1] = 1;

    for (int i = 2; i <= n; ++i)
        DP[i] = DP[i - 1] + DP[i - 2];

    return DP[n];
}

void main()
{
    cout << Fibonacci_Recursion(10) << endl;
    cout << Fibonacci_Memoization(10) << endl;
    cout << Fibonacci_Tabulation(10) << endl;
}

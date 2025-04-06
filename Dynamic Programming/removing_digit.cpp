#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  cin >> n;
  // Greedy Approach
  // int cnt = 0;

  // while (n != 0)
  // {
  //   int maxdigit = 0;
  //   int temp = n;
  //   while (temp > 0)
  //   {
  //     maxdigit = max(maxdigit, temp % 10);
  //     temp /= 10;
  //   }
  //   cnt++;
  //   n -= maxdigit;
  // }
  // cout << cnt << endl;
  // Dp Approach

  vector<int> dp(n + 1, 0);
  dp[0] = 0; // minimum number of steps required to convert number 0 to 0 after its digit subtraction.
  for (int i = 1; i <= n; i++)
  {
    string s = to_string(i);
    int minsteps = INT_MAX;
    for (char &c : s)
    {
      int digit = c - '0';
      if (digit != 0)
        minsteps = min(minsteps, dp[i - digit]);
    }
    dp[i] = minsteps + 1;
  }

  cout << dp[n] << endl;
}
int main()
{

  solve();

  return 0;
}
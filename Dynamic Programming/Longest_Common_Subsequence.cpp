#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int m, n;
  cin >> m >> n;
  int a[m];
  int b[n];
  for (int i = 0; i < m; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  // for (int i = 0; i <= m; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << dp[m][n] << endl;

  // Reconstruct and print LCS
  int i = m, j = n;
  vector<int> lcs;
  while (i > 0 && j > 0)
  {
    if (a[i - 1] == b[j - 1])
    {
      lcs.push_back(a[i - 1]);
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  reverse(lcs.begin(), lcs.end());
  for (int val : lcs)
    cout << val << ' ';
  cout << endl;
}
int main()
{

  solve();

  return 0;
}
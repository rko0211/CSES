#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(n, 0));

  // Fill the DP table
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i; j < n; j++)
    {
      if (i == j)
      {
        dp[i][j] = a[i];
      }
      else if (j == i + 1)
      {
        dp[i][j] = max(a[i], a[j]);
      }
      else
      {
        ll option1 = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
        ll option2 = a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
        dp[i][j] = max(option1, option2);
      }
    }
  }

  cout << dp[0][n - 1] << endl;

  return 0;
}
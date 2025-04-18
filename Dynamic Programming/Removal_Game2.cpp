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

  // Fill the DP table for the second player's maximum score
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i; j < n; j++)
    {
      if (i == j)
      {
        dp[i][j] = 0; // Second player gets nothing if only one element
      }
      else if (j == i + 1)
      {
        dp[i][j] = min(a[i], a[j]); // Second player gets the smaller element
      }
      else
      {
        // First player picks a[i], second player gets max from a[i+1..j]
        ll option1 = max(a[i + 1] + dp[i + 2][j], a[j] + dp[i + 1][j - 1]);
        // First player picks a[j], second player gets max from a[i..j-1]
        ll option2 = max(a[i] + dp[i + 1][j - 1], a[j - 1] + dp[i][j - 2]);
        // Second player's score is the maximum of the two options
        dp[i][j] = max(option1, option2);
      }
    }
  }
  // This is for 2nd player to have high score
  cout << dp[0][n - 1] << endl;

  return 0;
}
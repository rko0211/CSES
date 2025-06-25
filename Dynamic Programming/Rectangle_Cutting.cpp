#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int a, b;
  cin >> a >> b;
  // Greedy will not work here so we have to try out all possibilities and choose the best one
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
  for (int i = 1; i <= a; i++)
  {
    for (int j = 1; j <= b; j++)
    {
      if (i == j)
      {
        // This cut (i,i) always form square
        dp[i][j] = 0;
        continue;
      }

      // ans = min(Verticle Cut, Horizontal Cut)+1
      // Making verticle cut
      for (int v = 1; v < i; v++)
      {
        dp[i][j] = min(dp[i][j], dp[v][j] + dp[i - v][j] + 1);
      }
      // Making Horizontal cut
      for (int h = 1; h < j; h++)
      {
        dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1);
      }
    }
  }

  cout << dp[a][b] << endl;
}
int main()
{

  solve();
  return 0;
}
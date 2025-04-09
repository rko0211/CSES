#include <bits/stdc++.h>
using namespace std;
int main()
{

  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int m = s2.size();
  // cout << max(s1.size(), s2.size()) - lcs << endl;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  // Base case
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++)
  {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        int replace = dp[i - 1][j - 1] + 1;
        int removeFrom1stStringOrAddIn2ndStr = dp[i - 1][j] + 1;
        int removeFrom2ndStringOrAddIn1stStr = dp[i][j - 1] + 1;

        dp[i][j] = min({replace, removeFrom1stStringOrAddIn2ndStr, removeFrom2ndStringOrAddIn1stStr});
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
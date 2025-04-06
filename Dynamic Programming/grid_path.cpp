#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solve()
{
  int n;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  if (a[n - 1][n - 1] == '*')
  {
    cout << 0 << endl;
    return;
  }
  long long ans[n][n];
  ans[n - 1][n - 1] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (i == j && i == n - 1)
      {
        continue;
      }

      if (a[i][j] == '*')
      {
        ans[i][j] = 0;
        continue;
      }

      long long v1 = 0, v2 = 0;
      if ((j + 1) < n)
      {
        v1 = ans[i][j + 1];
      }
      if ((i + 1) < n)
      {
        v2 = ans[i + 1][j];
      }

      ans[i][j] = (v1 + v2) % mod;
    }
  }

  cout << ans[0][0] << endl;
}
int main()
{

  solve();

  return 0;
}
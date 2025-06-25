#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll solve(int i, int n, ll s1, ll total)
{
  if (i > n)
  {
    return (s1 == total / 2) ? 1 : 0;
  }

  // Pick i in subset A
  ll r1 = solve(i + 1, n, s1 + i, total);

  // Pick i in subset B (i.e., don't add it to s1)
  ll r2 = solve(i + 1, n, s1, total);

  return (r1 + r2) % mod;
}

int main()
{
  ll n;
  cin >> n;

  ll total = (n * (n + 1LL) / 2);

  // If total sum is odd, can't partition equally
  if (total % 2 != 0)
  {
    cout << 0 << endl;
    return 0;
  }

  // ll ways = solve(1, n, 0, total);

  // Divide by 2 to avoid double counting
  ll inv2 = (mod + 1) / 2;
  // cout << (ways * inv2) % mod << endl;

  vector<vector<ll>> dp(n + 1, vector<ll>(total));
  dp[0][0] = 1;

  for (int i = 1; i <= total; i++)
  {
    dp[0][i] = 0;
  }

  for (ll i = 1; i <= n; i++)
  {
    for (ll x = 0; x <= (total / 2); x++)
    {
      dp[i][x] = (((x < i) ? 0 : dp[i - 1][x - i]) + dp[i - 1][x]) % mod;
    }
  }

  cout << ((dp[n][(total / 2)]) * inv2) % mod << endl;

  return 0;
}

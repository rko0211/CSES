#include <bits/stdc++.h>
using namespace std;
// Complete search is a technique in programming in which we explore all cases in the solution space
long long f(int ind, int n, int a[], long long int g1, long long int g2, long long int &ans)
{
  if (ind >= n)
  {
    ans = min(ans, abs(g1 - g2));
    return ans;
  }

  return min(f(ind + 1, n, a, g1 + a[ind], g2, ans), f(ind + 1, n, a, g1, g2 + a[ind], ans));
}
void solve()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long ans = LLONG_MAX;
  long long g1 = 0, g2 = 0;
  f(0, n, a, g1, g2, ans);
  cout << ans << endl;
}
int main()
{

  solve();

  return 0;
}
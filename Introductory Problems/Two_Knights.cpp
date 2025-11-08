#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int k = 1; k <= n; k++)
  {
    long long m = k * k;

    long long total = (m * 1LL * (m - 1)) / 2; // K^2 C 2
    long long ans = total - (4 * (k - 1) * (k - 2));
    cout << ans << "\n";
  }
  return 0;
}
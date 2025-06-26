#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0; // Number of coins required to reach val =x =0
    for (int i = 1; i <= x; i++)
    {
        // For all value of sum
        for (int j = 0; j < n; j++)
        {
            if (c[j] <= i && dp[i - c[j]] != INT_MAX)
            {
                // Adding 1 means we need one more coin to get sum equal to x
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}
int main()
{

    solve();

    return 0;
}

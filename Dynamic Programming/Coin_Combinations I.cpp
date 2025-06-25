#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int countWays(int n, int x, const vector<int> &coins)
{
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    // To produce sum x we need to follow dp[x] ways
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
    }

    return dp[x];
}
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int ways = countWays(n, x, coins);
    cout << ways << endl;
}
int main()
{
    solve();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<vector<char>> g;
// map<pair<int, int>, string> memo;

// string dfs(int i, int j)
// {
//   if (i == n - 1 && j == n - 1)
//     return string(1, g[i][j]);

//   if (memo.count({i, j}))
//     return memo[{i, j}];

//   vector<string> candidates;

//   // Move right
//   if (j + 1 < n)
//   {
//     candidates.push_back(dfs(i, j + 1));
//   }

//   // Move down
//   if (i + 1 < n)
//   {
//     candidates.push_back(dfs(i + 1, j));
//   }

//   // Get the best (lex smallest) next string
//   sort(candidates.begin(), candidates.end());
//   string res = g[i][j] + candidates[0];

//   return memo[{i, j}] = res;
// }

// void solve()
// {
//   cin >> n;
//   g = vector<vector<char>>(n, vector<char>(n));
//   for (int i = 0; i < n; i++)
//     for (int j = 0; j < n; j++)
//       cin >> g[i][j];

//   string result = dfs(0, 0);
//   cout << result << endl;
// }

// int main()
// {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   solve();
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
char grid[N][N];
string dp[N];

// Stores only the current and previous row to save memory
void solve()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> grid[i];

  vector<string> prev(n), curr(n);

  // Base case
  prev[0] = grid[0][0];

  // Fill first row
  for (int j = 1; j < n; ++j)
    prev[j] = prev[j - 1] + grid[0][j];

  // Process rows
  for (int i = 1; i < n; ++i)
  {
    // First column
    curr[0] = prev[0] + grid[i][0];

    for (int j = 1; j < n; ++j)
    {
      if (prev[j] < curr[j - 1])
        curr[j] = prev[j] + grid[i][j];
      else
        curr[j] = curr[j - 1] + grid[i][j];
    }

    swap(prev, curr); // reuse vectors
  }

  cout << prev[n - 1] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

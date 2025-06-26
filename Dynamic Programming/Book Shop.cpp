#include <iostream>
#include <vector>
using namespace std;

// Function to compute the maximum number of pages we can get
int maximum_pages(int n, int x, vector<int> &prices, vector<int> &pages)
{
  // Create a 2D DP table
  // dp[i][j] = maximum pages using first i books and total price ≤ j
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  // Loop through all books (1 to n)
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 0; j <= x; ++j)
    {
      // First, don't take the current book
      dp[i][j] = dp[i - 1][j];

      // Now, check if we can take the current book (i-1 because 0-indexed arrays)
      if (j >= prices[i - 1])
      {
        // If we take it, we add its pages to the best value from the remaining capacity
        dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
      }
    }
  }

  // The answer is the best we can do using all books with total cost ≤ x
  return dp[n][x];
}

int main()
{
  int n, x;
  cin >> n >> x;

  // Read prices and pages for each book
  vector<int> prices(n), pages(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> prices[i]; // Cost of book i
  }
  for (int i = 0; i < n; ++i)
  {
    cin >> pages[i]; // Pages of book i
  }

  // Call the function and print the result
  int result = maximum_pages(n, x, prices, pages);
  cout << result << endl;

  return 0;
}

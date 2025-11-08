#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 1e7;
int first_pair[MAX_N + 1]; // first_pair[x] = some c such that x - c^2 is a perfect square

void precompute_two_squares()
{
  memset(first_pair, -1, sizeof(first_pair));
  int limit = sqrt(MAX_N);
  for (int i = 0; i <= limit; i++)
  {
    for (int j = i; j <= limit; j++)
    {
      int sum = i * i + j * j;
      if (sum <= MAX_N && first_pair[sum] == -1)
      {
        first_pair[sum] = i; // store the smaller one
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute_two_squares();

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    bool found = false;
    for (int a = 0; a * a <= n; a++)
    {
      for (int b = 0; b * b <= n - a * a; b++)
      {
        int remaining = n - a * a - b * b;
        if (first_pair[remaining] != -1)
        {
          int c = first_pair[remaining];
          int d = sqrt(remaining - c * c);
          cout << a << " " << b << " " << c << " " << d << "\n";
          found = true;
          break;
        }
      }
      if (found)
        break;
    }
  }
  return 0;
}
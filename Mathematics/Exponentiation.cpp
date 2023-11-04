#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll m = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll res = 1;
        while (b)
        {
            if (b & 1)
            {
 
                res = res * a % m;
            }
            a = a * a % m;
            b >>= 1;
        }
        cout << (res % m) << endl;
    }
 
    return 0;
}

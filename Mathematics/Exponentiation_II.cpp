#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll m = 1e9+7;
int binExpo(long long a, long long b, ll m)
{
   ll res=1;
   while(b>0)
   {
    if(b&1)
    {
      res = res*a%m;
    }
    a=a*1LL*a %m;
    b>>=1;
   }
   return res;
}
void solve()
{
  ll a,b,c;
  cin>>a>>b>>c;
  // As m is prime m-1;
 cout<<binExpo(a,binExpo(b,c,m-1),m)<<endl;;
}
int main()
{
int t;
cin>>t;
while(t--)
{
solve();
 
} 
    return 0;
}

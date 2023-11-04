// Two pointer approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
 
string s;
cin>>s;
int lo=0,hi=0;
int ans = INT_MIN;
int maxlen=0;
while(hi<s.size())
{
 
    if(s[lo]==s[hi])
    {
        maxlen= max(maxlen,(hi-lo+1));
        hi++;
    }
    else
    {
        ans = max(ans,maxlen);
        lo=hi;
    }
}
ans = max(ans,maxlen);
cout<<ans<<endl;
 
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
 
long long int n;
cin>>n;
int a[n-1];
long long sum1=0;
long long sum2=0;
for(int i=0;i<(n-1);i++)
{cin>>a[i];
sum1 +=a[i];
}
sum2 = (n*(n+1))/2;
cout<<(sum2-sum1)<<endl;
 
    return 0;
}

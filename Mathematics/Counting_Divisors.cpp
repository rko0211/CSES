#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x; cin>>x;
    int ans =0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            ans++;
            if(i!=x/i){
                ans++;
            }
        }
        
    }
    cout<<ans<<endl;
}
int main(){
 
int t; cin>>t;
while(t--){
    solve();
}
 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()

bool isprime(int n){
   if (n == 0 || n == 1) {
        return false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                return false;
                break;
            }
        }
    }
    return true;
}
void solve(){
   ll n,k;
   cin>>n>>k;
   ll a[n+1]={0};
   for(int i=1;i<=n;i++)cin>>a[i];
   ll ans=INT_MIN,tmp=0;
   for(int i=max(1ll,(n-2*k));i<=n;i++){
       for(int j=i+1;j<=n;j++){
         tmp=(i*j)-(k*(a[i]|a[j]));
         ans=max(ans,tmp);
       }
   }
   cout<<ans;
}

int main(){
   int t = 1;
   cin.tie(0);
   cin>>t;  
   while(t--){
      solve();
      cout<<endl;
   }
}
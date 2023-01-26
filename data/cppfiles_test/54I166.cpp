#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"    y is "<<y<<"    z is "<<z<<"    a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"    y is "<<y<<"    z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"    y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

ll power(ll a,ll b,ll m)
{
  ll ans=1;
  while(b)
  {
    if(b&1)
      ans=(ans*a)%m;
    b/=2;
    a=(a*a)%m;
  }
  return ans;
}
int main()
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
        
  ll t;cin>>t;
  while(t--) {
    ll n,k;cin>>n>>k;
    if(k == 0) {
      cout << 1 << endl;
      continue;
    }
    

    if(n & 1) {
      //isme sirf == hi ho skta
      ll ans = power(2,n-1,hell);
      ans += 1; ans %= hell;
      ans = power(ans,k,hell);
      cout << ans << endl;
    }
    else {
      /*// ==
      ll ans = power(2,n-1,hell);
      ans -= 1; ans+= hell; ans %= hell;
      ans = power(ans,k,hell);
  
      // >
      ll ans2 = power(2,n,hell) ;
      ans2 = power(ans2,k,hell);
      ans2 -= 1; ans2 += hell; ans2 %= hell;

      ll den = power(2,n,hell);
      den -= 1; den += hell; den %= hell;

      den = power(den,hell-2,hell);
      ans2 *= den;
      ans2 %= hell;

      ans += ans2;
      ans %= hell;
      cout << ans << endl;  */

      ll dp[k+2] = {0};
      ll mc = power(2,n-1,hell);
      mc -= 1; mc+= hell; mc %=hell;

      for(ll i=k;i>=1;i--) {
        if(i == k) {
          dp[i] = (mc + 1) % hell;
          continue;
        }
        dp[i] = (mc * (dp[i+1]))%hell;

        ll haha = power(2,k-i,hell);
        dp[i] += haha;
        dp[i] %= hell;
      }
      cout << dp[1] << endl;
    }
  }
}
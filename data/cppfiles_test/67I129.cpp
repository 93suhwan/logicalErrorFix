#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define setbits(x) __builtin_popcountll(x)
#define md (ll)1e9 + 7
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define f(i, j, n) for (ll i = j; i < n; i++)
#define r(i, j, n) for (ll i = n - 1; i >= j; i--)
void solve()
{
  int a,b,c;
  cin>>a>>b>>c;
  if(a>b)swap(a,b);
  if(b-a<=abs(c-b) || b-a<=abs(c-a) || b-a<=a){cout<<-1;return;}
  int ans;
  if(c<b and c>a){
    ans=a-(b-c);
    if(ans<1) ans=b+(c-a); 
  } 
  else{
    if(c<a)ans=b-(a-c);
    else ans=a+(c-b);
  }
  cout<<ans;
}
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inpput.txt", "r", stdin); //freopen("op.txt", "w", stdout);
#endif
  ll test_cases = 1;
  cin >> test_cases;
  for (ll t = 1; t <= test_cases; t++)
    solve(), cout << "\n";
  ;
  //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}
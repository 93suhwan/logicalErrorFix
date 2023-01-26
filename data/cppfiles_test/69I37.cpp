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
  vll v;
  for(int i=0;i<16;i++)
    v.pb(1<<i);
  int n;
  cin>>n;
  int ans=inf;
  for(auto str : v){
    string s1=to_string(n);
    string s2=to_string(str);
    int res=0,i=0,j=0;
    while (i<s1.length() and j<s2.length())
    {
      if(s1[i]==s2[j])i++,j++;
      else i++,res++;
    }
    res+=s1.length()-i+s2.length()-j;
    ans=min(ans,res);
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
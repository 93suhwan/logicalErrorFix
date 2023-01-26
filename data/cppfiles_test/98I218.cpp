#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18
 

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;


void solve()
{
  ll n;
  cin>>n;
  string s;
  cin>>s;
  ll cnt[n][2];
  clr(cnt);
  ll no0 = 0,no1 = 0;
  for(ll i=0;i<n;i++)
  {
    no0+=(s[i]=='a');
    no1+=(s[i]=='b');
    cnt[i][0] = no0;
    cnt[i][1] = no1;
  }
  for(ll i=0;i<n;i++)
  {
    for(ll j=i+1;j<n;j++)
    {
      ll n0 = cnt[j][0] - (i>0?cnt[i-1][0]:0ll);
      ll n1 = cnt[j][1] - (i>0?cnt[i-1][1]:0ll);
      if(n0!=n1)
      {
        cout<<(i+1)<<" "<<(j+1)<<"\n";
        return;
      }
    }
  }
  cout<<"-1 -1\n";
  return;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


cin>>t;


while(t--)
{
solve();
} 


return 0;
}
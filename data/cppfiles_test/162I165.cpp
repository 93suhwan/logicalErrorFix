#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define I_AM_SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);init_code();
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define all(x) (x).begin(),(x).end()
#define W(t) int t;cin>>t;while(t--)
#define printa(x); for(A n:x){cout<<n<<" ";}cout<<"\n";
#define printp(x); for(A n:x){cout<<n.ff<<" "<<n.ss<<"\n";}
#define U unsigned
#define I long long
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
#define OS(x) set<x>
#define OM(x,y) map<x,y>
#define V(x) vector<x>
#define VP(x,y) vector<pair<x,y>>
#define lb lower_bound
#define ub upper_bound
#define debug(x) cout<<#x<<" is "<<x<<"\n"
#define sz(x) (I)x.size()
#define P(x,y) pair<x,y>
#define INF 1e13
#define PBS(x) tree<x,null_type,less_equal<I>,rb_tree_tag,tree_order_statistics_node_update>
#define PBM(x,y) tree<pair<x, y>, null_type,less<pair<x, y> >,rb_tree_tag, tree_order_statistics_node_update>
#define digits(n) floor(log10(n)) + 1
#define isPerfectSq(x) ceil((D)sqrt((D)n))==floor((D)sqrt((D)n))
#define pi (D)acos(-1)
#define mod 1000000007
void init_code(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
}
void solve(){
  I n;
  cin>>n;
  I a[n],s[n];
  for(I i=0;i<n;i++)
  {
    cin>>a[i];
    s[i]=a[i];
  }
  for(I i=2;i<=n-1;i++)
  {
    if(a[i]<=2)
      continue;
    if(s[i]<=s[i-1] || s[i]<=s[i-2])
      continue;
    I temp=1;
    while(a[i-1]+temp<=a[i]-(3*temp))
    {
      temp++;
    }
    I t2=1;
    while(a[i-2]+(2*t2)<=a[i]-(3*t2))
    {
      t2++;
    }
    I te=max(temp,t2);
    // debug(te);
    // debug(i);
    s[i]-=(te*3);
    s[i-1]+=(te);
    s[i-2]+=(2*te);
  }
  I ans=INF;
  for(I i=0;i<n;i++)
  {
    ans=min(ans,s[i]);
  }
  // printa(s);
  cout<<ans<<endl;
}
int main()
{
  I_AM_SPEED
  I t=1;
  cin>>t; 
  while(t--)
    solve();
  return 0;

  // order_of_key(k) find_by_order(k);
}
        
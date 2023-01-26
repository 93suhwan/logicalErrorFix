
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define pb push_back
#define F first
#define S second
#define B begin()
#define E end()
#define in insert()
#define f(i, n) for (int i = 0; i < n; i++)
#define so(a) sort(a.begin(), a.end())
#define rso(a) sort(a.rbegin(), a.rend());
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef map<ll, ll> mll;
typedef priority_queue<ll> pql;
template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
/*no. of factors in least possible time*/
ll factor(ll n){ map <ll,ll> m;
  int ans=0;while(n%2==0){n=n/2;ans++;}
  m[2]=ans;
while(n%3==0){n/=3;ans++;m[3]++;}for(int i=1;;i++){ll z=6*i-1;if(z*z>n){break;}
if(n%z==0){while(n%z==0){n/=z;ans++;m[z]++;}}z+=2;if(n%z==0)
{while(n%z==0){n/=z;ans++;m[z]++;}}}if(n>1)ans++;return ans;}
void KEY()
{     
  ll n,m;
  cin>>n>>m;
  vl v(m);
  set <int> s;
  cin>>v;
  ll ans=0;
  for(int i=0;i<m;i++)
  {      
      ans+=distance(s.begin(),s.lower_bound(v[i]));
      s.insert(v[i]);
    
  }
  
  cout<<ans<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t = 1;
  cin >> t;
  while (t--)
    KEY();
}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
void __print(int x){cout<<x;}void __print(long long x){cout<<x;}
void __print(double x){cout<<x;}void __print(long double x){cout<<x;}
void __print(char x){cout<<'\''<<x<<'\'';}void __print(const char *x){cout<<'\"'<<x<<'\"';}
void __print(const string &x){cout<<'\"'<<x<<'\"';}void __print(bool x){cout<<(x?"True":"False");}
template<typename T,typename V>
void __print(const pair<T,V>&x){cout<<'{';__print(x.first);cout<<',';__print(x.second);cout<<'}';}
template<typename T>
void __print(const T &x){int f=0;cout<<'{';for(auto &i:x)cout<<(f++?",":""),__print(i);cout<<"}";}
void _print(){cout<<"]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define lp(i,a,b)       for (int i=a;i<=b;i++)
#define rp(i,a,b)       for (int i=a;i>=b;i--)
#define ms(a,x)         memset(a,x,sizeof a)
//#define int             long long 
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define rall(a)         a.rbegin(),a.rend()
#define pb              push_back
#define nl              cout<<"\n"
#define index           find_by_order
#define less            order_of_key
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        (((a)*(b))/(gcd(a,b)))
#define sq(a)           ((a)*(a))
#define sz(a)           (int) a.size()
#define mod             1000000007

void solve()
{
  string s;
  int k;
  cin>>s>>k;
  vector<int>ans;
  int n=sz(s);
  lp(i,0,n-1)
  {
    int x=s[i]-'0';
    if(x)
    {
      int cnt=n-i-1;
      int base=1;
      while(cnt--)
        base*=10;
      while(x--)
        ans.pb(base);
    }
  }
  while(sz(ans)>k)
  {
    int x=ans.back();
    ans.pop_back();
    ans.back()+=x;
  }
  if(sz(ans)==k)
  {
    for(int i:ans)
      cout<<i<<' ';
    nl;
    return;
  }
  int need=k-sz(ans);
  priority_queue<int>q;
  vector<int>now;
  lp(i,0,sz(ans)-1)
  {
    if(ans[i]>1)
      q.push(-ans[i]);
    else
      now.pb(ans[i]);
  }
  while(!q.empty())
  {
    int x=-q.top();
    q.pop();
    if(need==0)
    {
      now.pb(x);
      continue;
    }
    if(x>10)
    {
      string kos=to_string(x);
      n=sz(kos);
      n-=2;
      int vim=1;
      while(n--)
        vim*=10;
      q.push(-(vim*9));
      q.push(-(vim));
      need--;
      continue;
    }
    if(x>need)
    {
      int one=need;
      now.pb(x-one);
      while(one--)
        now.pb(1);
      need=0;
    }
    else
    {
      int one=x;
      while(one--)
        now.pb(1);
      need-=x-1;
    }
  }
  for(int i:now)
    cout<<i<<' ';
  nl;
}

signed main()
{
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  int T=1; 
  cin>>T;
  while(T--) solve();
  return 0;
}

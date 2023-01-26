#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define f1(i,n) for(ll i=1;i<=n;i++)
#define f0(i,n) for(ll i=0;i<n;i++)
#define fr(i,n) for(ll i=n-1;i>=0;i--)
#define fa(i,p,n) for(ll i=p;i<=n;i++)
#define f(i,a) for(auto &i:a)
#define vr vector <ll>
#define pb push_back
#define sn cout<<"\n";
#define sf cout<<endl;
#define mp(x,y) make_pair(x,y)
#define M map<ll,ll>
#define P pair<ll,ll>
#define S second
#define F first
#define PI 3.14159265
#define count1(x) __builtin_popcount(x)
#define G greater<ll>()
#define all(X) X.begin(),X.end()
#define allg(X) X.rbegin(),X.rend()
#define T  int t;cin>>t; while(t--)
#define OSS tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
// #define OSG tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update>
// cout<<(s.order_of_key(5)); strictly greater/less 
// cout<<*(s.find_by_order(6));index of that element
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MX=10000010;
const ll mod=1e9+7;
int main()
{
  sync
  //contest:)
  T
  {
    // deque<ll>q;
    ll n;cin>>n;
    OSS s;
    M m;
    ll c=0;
    vr v(n);
    f0(i,n)
    {
      cin>>v[i];
      s.insert(v[i]);
      ll temp=s.order_of_key(v[i]);      
      if(temp<(i-temp-m[v[i]]))
        c+=temp;
      else c+=(i-temp-m[v[i]]);
      m[v[i]]++;
    }
    cout<<c;
    sn
  }
  
  return 0;
}
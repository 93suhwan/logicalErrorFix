#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll                      long long
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define afo(i,x)                for(auto &i:x)
#define vi                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvi                    vector<vi>
#define mod                     1000000009
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve(){	
  int n,k;
  cin>>n>>k;

  int a[n];
  unordered_map<int,int>x;
  fo(i,0,n-1)
  {
    cin>>a[i];
    x[a[i]]++;
  }

  int ans[n];
  // set<int>z;
  unordered_map<int,int>col;
  int rem=0;
  afo(i,x)
  {
    if(i.second>=k)
      col[i.first]=1;
    else
      rem+=i.second;
  }

  int cnt=rem/k;
  cnt=cnt*k;
  int fill=1;
  int cntr=1;
  fo(i,0,n-1)
  {
    // cout<<col[a[i]]<<" ";
    if(col[a[i]]>0 and col[a[i]]<=k)
    {
      cout<<col[a[i]]<<" ";
      col[a[i]]++;
    }
    else if(col[a[i]]>0)
    {
      cout<<0<<" ";
    }
    else if(cntr<=cnt)
    {
      cout<<fill<<" ";
      cntr++;
      fill++;
      if(fill>k)
        fill=1;
    }
    else
      cout<<0<<" ";
    // cout<<endl;
  }

  cout<<endl;

}

signed main() {
 
  FIO
  INPUT();
  int t;
   t = 1;
  cin >> t;
	fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}
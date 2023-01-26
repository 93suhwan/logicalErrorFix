//Bismillah Hir Rehmanir Rahim
//Allah knows best
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using    namespace __gnu_pbds;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#define gap ' '
#include <bitset>
#define mini -10000000000000000
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define f(i, a, n) for(int i=a; i<n;i++)
#define ll long long
#define int long long
#define pi 3.141592653589793
#define vi              vector<ll>
#define si              set<ll>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;
#define erase_unique(st)        st.erase(unique(st.begin(), st.end()),st.end())
#define all(a) a.begin(), a.end()
typedef pair<ll, ll> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define deb(x)          cout << #x << " = " << x << endl
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld long double;
void solve() {
      ll n;
      cin >> n;
      set<pair<ll, ll>>st;
      vector<pair<ll, ll>>p;
      for(int i = 0; i < n; i++)
      {
        ll l, r;
        cin >> l >> r;
        st.in(mp(l, r));
        p.pb(mp(l, r));
      }
      vector<pair<pair<ll ,ll>, ll>>ans;
      for(int i = 0; i < n; i++)
      {
         for(int j = p[i].ff; j <= p[i].ss; j++)
         {
            auto pp = mp(p[i].ff, j - 1);
            auto qq = mp(j + 1, p[i].ss);
            if(st.find(pp) != st.end() && st.find(qq) != st.end())
            {
              ans.pb(mp(mp(p[i].ff, p[i].ss), j));
              break;
            }
            else
            {
              if(p[i].ss == p[i].ff)
              {
                ans.pb(mp(mp(p[i].ff, p[i].ss), j));
                break;
              }
              else if(st.find(pp) != st.end())
              {
               ans.pb(mp(mp(p[i].ff, p[i].ss), j));
               break;
              }
              else if(st.find(qq) != st.end())
              {
                ans.pb(mp(mp(p[i].ff, p[i].ss), j));
                break;
              }
            }
         }
      }
      for(auto x : ans)
      {
        cout << x.ff.ff << gap << x.ff.ss << gap << x.ss << endl;
      }
      cout << endl;
}
int32_t main()
{
  #ifndef DEBUG
   ios
   #else
   freopen("in", "r", stdin);
    //freopen("output.txt", "w", stdout);
   #endif
   int t=1;
   cin>>t;
   int ct=0;
   while(t--)
   {
    solve();  
   }
  rr ;
}
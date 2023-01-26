#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;

using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) -> iterator of kth element (in sorted fashion : low - high)
// order_of_key(x) -> #numbers strictly less than x

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
#define unq(a) sort(all(a));a.resize(unique(all(a)) - a.begin())
#define fi first
#define se second
//#define endl '\n'
 
using ll = long long;
using ld = long double;
using pii = pair<int , int>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);

int main(){
  sync
  #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tt = 1;
  //cin >> tt;

  while(tt--){
    int n;
    cin >> n;
    vector<int> a(n), rm(n), mk(n);
    for (int& x : a) cin >> x;
    
    vector<vector<int>> sq;

    auto rmv = [&](int x){
      int cnt = 0;
      vector<int> s;
      while(x){
        s.push_back(x);
        cnt++;
        if (__builtin_popcount(x) == 1){
          x = 0;
        }
        else{
          int tx = x, vl = 1;
          x = 0;
          while(tx){
            if (1 - (tx & 1)){
              x += vl;
            }
            vl <<= 1;
            tx >>= 1;
          }
          x++;
        }
      }
      s.push_back(0);
      sq.push_back(s);
      return cnt;
    };

    sort(all(a));
    int cnt = 0;
    map<int , int> idx;
    for (int i = 0; i < n; i++){
      rmv(a[i]);
      idx[a[i]] = i + 1;
    }
    map<int , int> cc, rcc;
    for (auto& s : sq){
      for (int x : s){
        cc[x] = 0;
      }
    }
    int m = 0;
    for (pii x : cc){
      cc[x.fi] = ++m;
      rcc[m] = x.fi;
    }
    vector<vector<int>> g(m + 1);
    for (auto& s : sq){
      for (int i = 1; i < s.size(); i++){
        g[cc[s[i - 1]]].push_back(cc[s[i]]);
        g[cc[s[i]]].push_back(cc[s[i - 1]]);
      }
    }

    for (int i = 1; i <= m; i++){
      unq(g[i]);
      // cout << rcc[i] << " :: " << endl;
      // for (int x : g[i])
      //   cout << rcc[x] << " ";
      // cout << endl;
    }

    struct data{
      array<int , 3> close;
      array<int , 2> open;
    };
    // A tree with max log(ai) length, root value = 0
    function<data(int c, int p)> dfs = [&](int c, int p){
      data ans; // {max close path length , max open length till c}
      ans.close[0] = 0; ans.close[1] = ans.close[2] = -1;
      ans.open[0] = ans.open[1] = -1;

      multiset<pii> big2;
      if (binary_search(all(a) , rcc[c])){
        big2.insert({0, c});
        ans.open[0] = 0; ans.open[1] = rcc[c];
      }
      for (const int& x : g[c]){
        if (x == p)
          continue;
        data dt = dfs(x, c);
        if (dt.close[0] > ans.close[0]){
          ans.close = dt.close;
        }
        dt.open[0]++;
        if (dt.open[0] > ans.open[0]){
          ans.open = dt.open;
        }
        if (dt.open[0] > 0){
          big2.insert({dt.open[0] , dt.open[1]});
        }
        if (big2.size() > 2){
          big2.erase(big2.begin());
        }
      }
      if (big2.size() == 2 && big2.begin()->fi + big2.rbegin()->fi > ans.close[0]){
        ans.close = {big2.begin()->fi + big2.rbegin()->fi, big2.begin()->se, big2.rbegin()->se};
      }
      return ans;
    };
    data ans = dfs(cc[0], -1);
    cout << idx[ans.close[1]] << " " << idx[ans.close[2]] << " " << ans.close[0] << endl;
  }
 
  cerr << "processor time: " << clock() / (double) CLOCKS_PER_SEC << "s    ";
  return 0;
}
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
#define endl '\n'
 
using ll = long long;
using ld = long double;
using pii = pair<int , int>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);

const int N = 2e5 + 1, B = 30;
vector<int> g[N * B];
int a[N];
int present[N * B], rcc[N * B], vis[N * B];

struct Data{
  array<int , 3> close;
  array<int , 2> open;
};

Data dfs(int c){
  vis[c] = 1;
  Data ans; // {max close path length , max open length till c}
  ans.close[0] = 0; ans.close[1] = ans.close[2] = -1;
  ans.open[0] = ans.open[1] = -1;

  set<pii> big2;
  if (present[c]){
    big2.insert({0, rcc[c]});
    ans.open[0] = 0; ans.open[1] = rcc[c];
  }
  for (const int& x : g[c]){
    if (vis[x])
      continue;
    Data dt = dfs(x);
    if (dt.close[0] > ans.close[0]){
      ans.close = dt.close;
    }
    dt.open[0]++;
    if (dt.open[0] > ans.open[0] && dt.open[0] > 0){
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
}

int main(){
  sync
  #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tt = 1;
  //cin >> tt;

  while(tt--){
    int n = 2e5;
    cin >> n;
    for (int i = 0; i < n; i++){
        //a[i] = rng() % 1000000000LL + 1;
        cin >> a[i];
    }
    
    vector<vector<int>> sq;
    auto rmv = [&](int x){
      int cnt = 0, msb = -1;
      vector<int> s;
      for (int i = 29; i >= 0; i--){
          if (x & (1 << i)){
              msb = i;
              break;
          }
      }
      while(msb >= 0){
        s.push_back(x);
        cnt++;
        if (__builtin_popcount(x) == 1){
          msb = -1;
        }
        else{
          x = ((1 << (msb + 1)) - 1) ^ x;
          x++;
          while(msb >= 0 && !(x & (1 << msb))){
            msb--;
          }
        }
      }
      s.push_back(0);
      //for (int w : s) cout << w << " "; cout << endl;
      sq.push_back(s);
      return cnt;
    };

    int cnt = 0;
    map<int , int> idx;
    for (int i = 0; i < n; i++){
      rmv(a[i]);
      idx[a[i]] = i + 1;
    }
    map<int , int> cc;
    int m = 0;
    for (auto& s : sq){
      for (int& x : s){
        if (cc.count(x)){
            x = cc[x];
        }
        else{
            cc[x] = ++m;
            rcc[m] = x;
            x = m;
        }
      }
    }
    for (auto& s : sq){
      for (int i = 1; i < s.size(); i++){
        g[s[i - 1]].push_back(s[i]);
        g[s[i]].push_back(s[i - 1]);
      }
    }
    for (int x : a){
      present[cc[x]] = 1;
    }
    // A tree with max log(ai) length, root value = 0
    Data ans = dfs(cc[0]);
    cout << idx[ans.close[1]] << " " << idx[ans.close[2]] << " " << ans.close[0] << endl;
  }
 
  cerr << "processor time: " << clock() / (double) CLOCKS_PER_SEC << "s    ";
  return 0;
}
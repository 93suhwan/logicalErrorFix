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

const int inf = 1e9;

struct fenwick{
  int n;
  vector<int> f;

  fenwick(int _n = 0){
    n = _n;
    f.clear();
    f.resize(n + 1 , inf);
  }

  void init(int _n){
    n = _n;
    f.clear();
    f.resize(n + 1 , inf);
  }

  void upd(int x, int v){
    for (int i = x; i <= n; i += (i & -i)){
      f[i] = min(f[i], v);
    }
  }

  int get(int x){
    int r = inf;
    for (int i = x; i > 0; i -= (i & -i)){
      r = min(r, f[i]);
    }
    return r;
  }
};

int main(){
  sync
  #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tt = 1;
  //cin >> tt;

  while(tt--){
    const int mod = 998244353;
    int n;
    cin >> n;
    vector<long long> x(n), val(n);
    fenwick fk; fk.init(n);
    map<int , int> mp;

    for (int i = 0; i < n; i++){
      cin >> x[i];
      mp[x[i]] = 0;
    }
    int at = 1;
    for (pii x : mp){
      mp[x.fi] = at++;
    }
    for (int i = 0; i < n; i++){
      val[i] = mp[x[i]];
    }
    vector<long long> dp(n), sf0(n + 1), sf1(n + 1);
    dp[n - 1] = x[n - 1];
    fk.upd(val[n - 1] , n - 1);
    sf0[n - 1] = dp[n - 1] % mod;
    sf1[n - 1] = (mod - dp[n - 1]) % mod;
    if ((n - 1) & 1){
      swap(sf0[n - 1] , sf1[n - 1]);
    }

    auto get = [&](int l, int r){
      ll ans = 0;
      if (l <= r){
        if (l & 1){
          ans = ((sf1[l] - sf1[r + 1]) % mod + mod) % mod;
        }
        else{
          ans = ((sf0[l] - sf0[r + 1]) % mod + mod) % mod;
        }
      }
      return ans;
    };

    auto get_pf = [&](int at, int h){
      ll ans = 0;
      if (at == n - 1){
        ans = h % mod;
      }
      else{
        assert(h > x[at + 1]);
        ans = ((x[at + 1] - 1) * dp[at + 1]) % mod;
        ans += ((h - x[at + 1]) * dp[at + 1]) % mod;
        ans %= mod;
      }
      return ans;
    };

    for (int i = n - 2; i >= 0; i--){
      if (x[i] > x[i + 1]){
        dp[i] = ((x[i + 1] - 1) * dp[i + 1]) % mod;
        dp[i] += ((x[i] - x[i + 1]) * dp[i + 1]) % mod;
        dp[i] %= mod;
      }
      else{
        int l, r;
        l = i + 1;
        ll sub = 0;
        int ix = fk.get(val[i] - 1);
        if (ix == inf){
          r = n - 1;
        }
        else{
          r = ix - 1;
        }
        sub = (x[i] * get(l , r)) % mod;
        if ((r - l + 1) % 2 == 0){
          sub += get_pf(r , x[i]); sub %= mod;
        }
        else{
          sub -= get_pf(r, x[i]); sub = (mod + sub) % mod;
        }
        //cout << i << " :: " << l  << " " << r << " " << get(l , r) << " " << sub << endl << flush;
        dp[i] = sub;
      }
      fk.upd(val[i] , i);
      sf0[i] = dp[i] % mod;
      sf1[i] = (mod - dp[i]) % mod;
      if (i & 1){
        swap(sf0[i] , sf1[i]);
      }
      sf0[i] += sf0[i + 1]; sf0[i] %= mod;
      sf1[i] += sf1[i + 1]; sf1[i] %= mod;
    }
    cout << dp[0] << endl;
  }
 
  cerr << "processor time: " << clock() / (double) CLOCKS_PER_SEC << "s    ";
  return 0;
}
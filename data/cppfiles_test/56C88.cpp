#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using str = string;
template <class T>
bool min_val(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool max_val(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const ll MOD = 1e9 + 7;
const ll MAX = 1e9 + 7;
const ll MIN = -1e9 + 7;
long long madd(long long a, long long b) { return (a + b) % MOD; }
long long msub(long long a, long long b) {
  return (((a - b) % MOD) + MOD) % MOD;
}
long long mmul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long mpow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp % 2 == 1) {
      res = (res * base) % MOD;
    }
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return res;
}
long long minv(long long base) { return mpow(base, MOD - 2); }
long long mdiv(long long a, long long b) { return mmul(a, minv(b)); }
long long int mmul_64(long long int a, long long int b, long long int MOD) {
  long long int x = 0, y = a % MOD;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % MOD;
    }
    y = (y * 2LL) % MOD;
    b /= 2;
  }
  return x % MOD;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
map<string, ll> mp;
vector<vector<ll>> allowed(7);
unordered_map<ll, ll, custom_hash> color;
unordered_map<ll, ll, custom_hash> tree;
unordered_map<ll, unordered_map<ll, ll, custom_hash>, custom_hash> DP;
void init() {
  mp["white"] = 1;
  mp["yellow"] = 2;
  mp["green"] = 3;
  mp["blue"] = 4;
  mp["red"] = 5;
  mp["orange"] = 6;
  allowed[1] = {3, 4, 5, 6};
  allowed[2] = {3, 4, 5, 6};
  allowed[3] = {1, 2, 5, 6};
  allowed[4] = {1, 2, 5, 6};
  allowed[5] = {1, 2, 3, 4};
  allowed[6] = {1, 2, 3, 4};
}
void DFS(ll curr_node) {
  if (tree[curr_node] == 0) {
    return;
  }
  DFS(2 * curr_node);
  DFS(2 * curr_node + 1);
  vector<ll> allow;
  if (tree[curr_node] == 2) {
    allow = {color[curr_node]};
  } else {
    allow = {1, 2, 3, 4, 5, 6};
  }
  if (tree[2 * curr_node] > 0 && tree[2 * curr_node + 1] > 0) {
    for (auto i : allow) {
      for (auto j : allowed[i]) {
        for (auto k : allowed[i]) {
          DP[curr_node][i] =
              madd(DP[curr_node][i],
                   mmul(DP[2 * curr_node][j], DP[2 * curr_node + 1][k]));
        }
      }
    }
  } else if (tree[2 * curr_node] > 0) {
    for (auto i : allow) {
      for (auto j : allowed[i]) {
        DP[curr_node][i] = madd(DP[curr_node][i], DP[2 * curr_node][j]);
      }
    }
  } else if (tree[2 * curr_node + 1] > 0) {
    for (auto i : allow) {
      for (auto j : allowed[i]) {
        DP[curr_node][i] = madd(DP[curr_node][i], DP[2 * curr_node + 1][j]);
      }
    }
  } else {
    DP[curr_node][color[curr_node]] = 1;
  }
}
void solve() {
  init();
  ll k, n;
  cin >> k >> n;
  ll num_affected = 0;
  for (ll i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    string s;
    cin >> s;
    if (tree[x] == 0) num_affected++;
    tree[x] = 2;
    color[x] = mp[s];
    x /= 2;
    while (x > 0 && tree[x] == 0) {
      tree[x] = 1;
      x /= 2;
      num_affected++;
    }
  }
  DFS(1);
  ll total_nodes = (1LL << k) - 1;
  ll not_affected = total_nodes - num_affected;
  ll ans1 = mpow(4, not_affected);
  ll ans2 = 0;
  for (ll i = 1; i <= 6; i++) {
    ans2 = madd(ans2, DP[1][i]);
  }
  ll ans = mmul(ans1, ans2);
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(15) << fixed;
  ll t = 1;
  for (ll i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

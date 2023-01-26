#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename TC,
          typename T = typename enable_if<!is_same<TC, string>::value,
                                          typename TC::value_type>::type>
ostream &operator<<(ostream &os, const TC &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
struct dbg {
  template <typename T>
  dbg &operator<<(__attribute__((unused)) const T &args) {
    return *this;
  }
};
using ll = int64_t;
using ull = uint64_t;
constexpr int MOD = 1e9 + 7;
void solve() {
  ll n, m;
  cin >> n >> m;
  int q, alive = n;
  vector<ll> friends(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    alive -= friends[min(u, v)]++ == 0;
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    switch (type) {
      case 1: {
        int u, v;
        cin >> u >> v;
        alive -= friends[min(u, v)]++ == 0;
        break;
      }
      case 2: {
        int u, v;
        cin >> u >> v;
        alive += --friends[min(u, v)] == 0;
        break;
      }
      case 3: {
        cout << alive << "\n";
        break;
      }
    };
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

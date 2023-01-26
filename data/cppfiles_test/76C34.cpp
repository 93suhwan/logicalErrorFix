#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
ll mod = 1e9 + 7;
int const N = 3e5 + 100;
mt19937 rnd;
ll random(ll limit) {
  uniform_int_distribution<ll> uniform_dist(0, limit);
  return uniform_dist(rnd);
}
ll bpow(ll a, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p % 2) {
      res = res * a % mod;
    }
    a = a * a % mod;
    p /= 2;
  }
  return res;
}
ll inv(ll a) { return bpow(a, mod - 2); }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> x(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    x[a].insert(b);
    x[b].insert(a);
  }
  int it_num = 2e6;
  vector<int> ans(5);
  while (it_num) {
    it_num--;
    bool f1 = 1, f2 = 1;
    for (int i = 0; i < 5 && (f1 || f2); i++) {
      ans[i] = random(n - 1);
      for (int j = 0; j < i; j++) {
        if (ans[i] == ans[j]) {
          f1 = 0;
          f2 = 0;
        }
        if (x[ans[j]].count(ans[i]) == 0)
          f1 = 0;
        else
          f2 = 0;
      }
    }
    if (f1 || f2) {
      for (int i = 0; i < 5; i++) cout << ans[i] + 1 << ' ';
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rnd = mt19937(956231);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}

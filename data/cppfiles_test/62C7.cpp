#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  ll answer = 0;
  int mid = 2e3;
  vector<set<ll>> bad(mid * 2);
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= m + 1; ++j) {
      if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
        bad[i - j + mid].insert(i);
        continue;
      }
      answer += min(i, j) * 2 - 1;
      answer += min(i, j - 1);
      answer += min(i - 1, j);
    }
  }
  auto count_ways = [&](int x, int y) {
    int d = x - y + mid;
    ll res = 0;
    {
      int d1 = d;
      int d2 = d + 1;
      auto it = bad[d1].upper_bound(x);
      auto it2 = bad[d2].upper_bound(x);
      int L = min((x - (*prev(it))) * 2, (x - (*prev(it2))) * 2 + 1);
      int R = min(((*it) - x) * 2, ((*it2) - (x + 1)) * 2 + 1);
      res += 1ll * L * R;
    }
    {
      int d1 = d;
      int d2 = d - 1;
      auto it = bad[d1].upper_bound(x);
      auto it2 = bad[d2].upper_bound(x - 1);
      int L = min((x - (*prev(it))) * 2, (x - 1 - (*prev(it2))) * 2 + 1);
      int R = min(((*it) - x) * 2, ((*it2) - x) * 2 + 1);
      res += 1ll * L * R;
    }
    assert(res >= 2);
    res--;
    return res;
  };
  for (int _ = 0; _ < (q); ++_) {
    int x, y;
    cin >> x >> y;
    int d = x - y + mid;
    if (bad[d].count(x)) {
      bad[d].erase(x);
      answer += count_ways(x, y);
    } else {
      answer -= count_ways(x, y);
      bad[d].insert(x);
    }
    cout << answer << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  for (int _ = 0; _ < (tests); ++_) {
    solve();
  }
  return 0;
}

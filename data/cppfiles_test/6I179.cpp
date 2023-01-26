#include <bits/stdc++.h>
const long long N = 3 * 1e5 + 5;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long inf = 1e18;
using namespace std;
vector<long long> s, x, y;
long long modpow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
void precompute() {}
template <typename T>
bool compare(const T &a, const T &b) {
  return a.first < b.first;
}
vector<long long> bit;
void add(long long idx, long long delta, long long n) {
  for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
}
long long sum(long long r) {
  long long ret = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
  return ret;
}
long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
void solve() {
  long long n, m;
  cin >> n >> m;
  set<int> s[n];
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    s[a].insert(b);
    s[b].insert(a);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i].size() == 0)
      ans++;
    else {
      auto it = s[i].end();
      it--;
      if (s[i].size() == 0 or *it < i) ans++;
    }
  }
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long val;
    cin >> val;
    if (val == 1) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (s[u].size() == 0)
        ans--;
      else {
        auto it = s[u].end();
        it--;
        if (*it < i) ans--;
      }
      if (s[v].size() == 0)
        ans--;
      else {
        auto it = s[v].end();
        it--;
        if (*it < i) ans--;
      }
      s[u].insert(v);
      s[v].insert(u);
      if (s[u].size() == 0)
        ans++;
      else {
        auto it = s[u].end();
        it--;
        if (*it < i) ans++;
      }
      if (s[v].size() == 0)
        ans++;
      else {
        auto it = s[v].end();
        it--;
        if (*it < i) ans++;
      }
    } else if (val == 2) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (s[u].size() == 0)
        ans--;
      else {
        auto it = s[u].end();
        it--;
        if (*it < i) ans--;
      }
      if (s[v].size() == 0)
        ans--;
      else {
        auto it = s[v].end();
        it--;
        if (*it < i) ans--;
      }
      s[u].erase(v);
      s[v].erase(u);
      if (s[u].size() == 0)
        ans++;
      else {
        auto it = s[u].end();
        it--;
        if (*it < i) ans++;
      }
      if (s[v].size() == 0)
        ans++;
      else {
        auto it = s[v].end();
        it--;
        if (*it < i) ans++;
      }
    } else if (val == 3) {
      cout << ans << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t = 1;
  precompute();
  long long ctr = 0;
  while (t--) {
    ctr++;
    solve();
    cout << "\n";
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}

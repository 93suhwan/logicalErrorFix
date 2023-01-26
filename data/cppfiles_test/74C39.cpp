#include <bits/stdc++.h>
using namespace std;
mt19937 rng(1234);
const long long maxn = 200007;
const long long inf = LLONG_MAX / 4;
long long n;
long long a[maxn], b[maxn];
set<long long> s;
unordered_map<long long, long long> mp;
unordered_map<long long, long long> le[15], ri[15];
bool vis[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.precision(15);
  cin >> n;
  for (long long i = 0; i < (long long)(n); ++i) cin >> a[i];
  for (long long i = 0; i < (long long)(n); ++i) {
    if (s.find(a[i]) != s.end()) {
      cout << "YES\n0 ";
      for (long long j = 0; j < (long long)(n); ++j) {
        if (i == j) continue;
        cout << a[j] << " ";
      }
      return 0;
    }
    s.insert(a[i]);
  }
  if (n >= 4) {
    bool ok = 0;
    for (long long i = 0; i < (long long)(n); ++i) {
      if (a[i] & 1) continue;
      ok = 1;
    }
    if (ok) {
      long long x = -1, y = -1;
      for (long long i = 0; i < (long long)(n); ++i) {
        if (a[i] & 1)
          x = i;
        else
          y = i;
      }
      long long s = -1, t = -1;
      for (long long i = 0; i < (long long)(n); ++i) {
        if (i == x || i == y) continue;
        if (s == -1)
          s = i;
        else
          t = i;
      }
      auto solve = [&](long long s, long long t, long long d) {
        long long x = (a[s] + a[t] - a[d]) / 2;
        cout << "YES\n" << x << " " << a[s] - x << " " << a[t] - x << " ";
        for (long long i = 0; i < (long long)(n); ++i) {
          if (i == s || i == t || i == d) continue;
          cout << a[i] - x << " ";
        }
      };
      if ((a[s] + a[t] + a[y]) % 2) {
        solve(s, t, x);
      } else {
        solve(s, t, y);
      }
      return 0;
    }
    auto solve2 = [&](long long mask, long long mask2) {
      cout << "YES\n";
      vector<long long> L, R;
      L.clear(), R.clear();
      for (long long i = 0; i < (long long)(n); ++i) {
        if (mask >> i & 1) L.push_back(a[i]), vis[i] = 1;
        if (mask2 >> i & 1) R.push_back(a[i]), vis[i] = 1;
      }
      cout << 0 << " ";
      long long ret = 0;
      for (long long i = 0; i < (long long)((long long)(L).size()); ++i) {
        ret = L[i] - ret;
        cout << ret << " ";
        ret = R[i] - ret;
        if (ret) cout << ret << " ";
      }
      for (long long i = 0; i < (long long)(n); ++i) {
        if (!vis[i]) cout << a[i] << " ";
      }
    };
    long long m = min(n, 30ll), k = m / 2;
    vector<long long> p;
    p.clear();
    for (long long i = 0; i < (long long)(m - k); ++i) p.push_back(0);
    for (long long i = 0; i < (long long)(k); ++i) p.push_back(1);
    do {
      long long sum = 0, mask = 0;
      for (long long i = 0; i < (long long)(m); ++i) {
        if (p[i]) sum += a[i], mask |= (1 << i);
      }
      if (mp[sum]) {
        long long mask2 = mp[sum], com = mask & mask2;
        mask ^= com, mask2 ^= com;
        solve2(mask, mask2);
        return 0;
      }
      mp[sum] = mask;
    } while (next_permutation(begin(p), end(p)));
    cout << "NO\n";
    return 0;
  }
  if (n == 3) {
    if ((a[0] + a[1] + a[2]) % 2) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n";
    long long x = a[0] + a[1] - a[2];
    x /= 2;
    cout << x << " " << a[0] - x << " " << a[1] - x;
    return 0;
  }
  cout << "NO\n";
  return 0;
}

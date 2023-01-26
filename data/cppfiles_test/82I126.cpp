#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#pragma GCC optimize("Ofast")
using namespace std;
mt19937 gen(time(0));
mt19937 gen2(228);
mt19937_64 gen64(time(0));
long long inf = (long long)1e18 + 228;
const long long mod = 998244353;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q, m;
  cin >> n >> q >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long K = 400;
  if (m > K) {
    vector<vector<long long>> ST(20, vector<long long>(n));
    vector<long long> lgs(n + 1, 0);
    for (long long i = 2; i <= n; ++i) {
      lgs[i] = lgs[i / 2] + 1;
    }
    for (long long j = 0; j < 20; ++j) {
      for (long long i = 0; i < n; ++i) {
        if (j == 0) {
          ST[j][i] = a[i];
        } else if (i + (1 << (j - 1)) < n) {
          ST[j][i] = min(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
        }
      }
    }
    function<long long(long long, long long)> ask = [&](long long l,
                                                        long long r) {
      long long curLg = lgs[r - l + 1];
      return min(ST[curLg][l], ST[curLg][r - (1 << curLg) + 1]);
    };
    for (long long i = 0; i < q; ++i) {
      long long x, y;
      cin >> x >> y;
      --x;
      --y;
      long long ans = a[x];
      long long p = x + m;
      while (p <= y) {
        ans += ask(x, p);
        p += m;
      }
      cout << ans << '\n';
    }
  } else {
    vector<vector<pair<long long, long long>>> queries(n);
    for (long long i = 0; i < q; ++i) {
      long long x, y;
      cin >> x >> y;
      queries[x - 1].emplace_back(y - 1 - m, i);
    }
    vector<long long> b(n);
    for (long long i = 0; i < n; ++i) {
      long long res = inf;
      for (long long j = i; j <= min(n - 1, i + m); ++j) {
        res = min(res, a[j]);
      }
      b[i] = res;
    }
    vector<long long> ans(q);
    vector<vector<pair<long long, long long>>> v(m);
    for (long long i = n - 1; i > -1; --i) {
      while (v[i % m].size() && b[v[i % m].back().first] >= b[i]) {
        v[i % m].pop_back();
      }
      long long newSum = 0;
      if (v[i % m].size()) {
        newSum =
            (v[i % m].back().first - i) / m * b[i] + v[i % m].back().second;
      } else {
        newSum = (n - i + m - 1) / m * b[i];
      }
      v[i % m].emplace_back(i, newSum);
      for (auto [r, idx] : queries[i]) {
        long long curAns = a[i] + v[i % m].back().second;
        long long L = -1, R = v[i % m].size() - 1;
        while (R - L > 1) {
          long long M = (L + R) / 2;
          if (v[i % m][M].first <= r) {
            R = M;
          } else {
            L = M;
          }
        }
        long long rBorder = n;
        if (L != -1) {
          curAns -= v[i % m][L].second;
          rBorder = v[i % m][L].first;
        }
        curAns -= (rBorder - r + m - 2) / m * b[v[i % m][L + 1].first];
        ans[idx] = curAns;
      }
    }
    for (auto x : ans) {
      cout << x << '\n';
    }
  }
}

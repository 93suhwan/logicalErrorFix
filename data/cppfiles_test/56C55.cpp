#include <bits/stdc++.h>
using namespace std;
const long long C = 6;
const long long K = 60;
const long long P = 1e9 + 7;
long long dp[K];
long long mod(long long x) { return x > 0 ? x : -x; }
long long invalid(long long x) { return mod(x) == 3 or x == 0; };
void fillDp() {
  for (long long k = 0; k < K; k++) {
    if (k == 0) {
      dp[k] = 1;
      continue;
    }
    for (long long c1 = 0; c1 < C; c1++) {
      for (long long c2 = 0; c2 < C; c2++) {
        if (invalid(c1) or invalid(c2)) continue;
        dp[k] = (dp[k] + dp[k - 1] * dp[k - 1]) % P;
      }
    }
  }
}
long long k;
map<long long, long long> filled;
set<long long> haveChildren;
vector<long long> count(long long u, long long d) {
  if (not haveChildren.count(u)) {
    if (filled.count(u)) {
      long long c = filled[u];
      vector<long long> ans(C);
      ans[c] = dp[k - 1 - d];
      return ans;
    }
    return vector<long long>(C, dp[k - 1 - d]);
  }
  auto v1 = count(2 * u, d + 1);
  auto v2 = count(2 * u + 1, d + 1);
  vector<long long> ans(C);
  for (long long c = 0; c < C; c++) {
    if (filled.count(u) and filled[u] != c) continue;
    for (long long c1 = 0; c1 < C; c1++) {
      for (long long c2 = 0; c2 < C; c2++) {
        if (invalid(c - c1) or invalid(c - c2)) continue;
        ans[c] = (ans[c] + v1[c1] * v2[c2]) % P;
      }
    }
  }
  return ans;
}
signed main() {
  iostream::sync_with_stdio(false);
  fillDp();
  map<string, long long> colorEncoding = {{"white", 0}, {"yellow", 3},
                                          {"green", 1}, {"blue", 4},
                                          {"red", 2},   {"orange", 5}};
  long long n;
  cin >> k >> n;
  for (long long i = 0; i < n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    for (long long k = v / 2; k >= 1; k /= 2) {
      haveChildren.insert(k);
    }
    assert(colorEncoding.count(s));
    filled[v] = colorEncoding[s];
  }
  auto v = count(1, 0);
  long long ans = accumulate(v.begin(), v.end(), 0ll) % P;
  cout << ans << '\n';
  assert(cin);
}

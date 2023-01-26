#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx", "sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
signed main(signed argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<long long> b(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<long long> dp(n + 1, LLONG_MAX);
  vector<long long> bt(n + 1, -1);
  dp[n] = 0;
  long long mn = n - 1;
  for (long long i = n; i >= 1; i--) {
    if (dp[i] == LLONG_MAX) break;
    long long cur = i + b[i];
    long long l = cur - a[cur];
    for (long long j = l; j <= mn; j++) {
      dp[j] = min(dp[j], dp[cur] + 1);
      bt[j] = i;
    }
    mn = min(l - 1, mn);
  }
  if (dp[0] == LLONG_MAX) {
    cout << -1;
  } else {
    long long cur = 0;
    vector<long long> rt;
    while (cur != n) {
      rt.push_back(cur);
      cur = bt[cur];
    }
    cout << rt.size() << '\n';
    for (long long i = (long long)rt.size() - 1; i >= 0; i--) {
      cout << rt[i] << ' ';
    }
  }
}

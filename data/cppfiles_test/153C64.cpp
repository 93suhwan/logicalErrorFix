#include <bits/stdc++.h>
using namespace std;
void io(string in = "", string out = "", string err = "") {
  if (fopen(in.c_str(), "r")) {
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
  }
}
void conv();
int main() {
  io(""
     ".inp",
     ""
     ".out");
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q = 1;
  while (Q--) {
    conv();
  }
  return 0;
}
const int md = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  if (a < 0) a += md;
  return a;
}
int mul(int a, int b) { return (unsigned long long)a * b % md; }
void conv() {
  int n;
  cin >> n;
  vector<array<int, 26>> cnt(1 << n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cnt[1 << i].fill(0);
    for (char c : s) ++cnt[1 << i][c - 'a'];
  }
  vector<int> dp(1 << n);
  dp[0] = 0;
  for (int i = 1; i < 1 << n; ++i) {
    if (i & i - 1) {
      int w = i & i - 1, v = w ^ i;
      for (int j = 0; j < 26; ++j) cnt[i][j] = min(cnt[v][j], cnt[w][j]);
    }
    dp[i] = __builtin_parity(i) ? 1 : md - 1;
    for (int x : cnt[i]) dp[i] = mul(dp[i], x + 1);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 1; j < 1 << n; ++j)
      if (j >> i & 1) dp[j] = add(dp[j], dp[j ^ 1 << i]);
  long long res = 0;
  for (int i = 1; i < 1 << n; ++i) {
    int k = 0, s = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) ++k, s += j + 1;
    }
    res ^= (long long)dp[i] * k * s;
  }
  cout << res;
}

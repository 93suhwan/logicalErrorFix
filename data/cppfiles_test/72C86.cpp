#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void ioi(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
long long n, w, k, dp[20][2][1 << 10][2], ans[100005];
string s;
long long f(long long a = n - 1, long long b = 1, long long c = (1LL << 10) - 1,
            long long no = 1) {
  if (__builtin_popcountll(c) < 10 - k) return 0;
  if (a < 0) return 1;
  long long &d = dp[a][b][c][no];
  if (!b && ~d) return d;
  long long e = s[a] - '0', g = 0;
  for (long long i = 0; i <= (b ? e : 9); i++) {
    if (!(no && !i))
      g += f(a - 1, b && (i == e), (c & ~(1LL << i)), no && !i);
    else
      g += f(a - 1, b && (i == e), c, no && !i);
  }
  return b ? g : d = g;
}
long long calc(long long x) {
  s = to_string(x);
  n = (int)s.size();
  reverse(s.begin(), s.end());
  return f();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(10);
  ;
  vector<pair<long long, long long>> q[11];
  long long T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> w >> k;
    q[k].push_back(make_pair(w, i));
  }
  for (int K = 1; K <= 10; K++) {
    memset(dp, -1, sizeof dp);
    k = K;
    for (auto x : q[K]) {
      w = x.first;
      long long l = w, r = (1LL << 42);
      w = calc(w - 1);
      while (l != r) {
        long long tm = (l + r) / 2;
        if (w < calc(tm))
          r = tm;
        else
          l = tm + 1;
      }
      ans[x.second] = l;
    }
  }
  for (int i = 1; i <= T; i++) cout << ans[i] << "\n";
  return 0;
}

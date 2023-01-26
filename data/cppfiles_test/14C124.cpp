#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void ioi(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
long long n, m, k, a[2005], p[2005];
void solve() {
  k = (1LL << 60);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n + 1; i++) p[i] = -(1LL << 60);
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 1; j--) {
      p[j] = max(p[j], p[j - 1] + (a[i] == j));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (m <= p[i]) k = min(k, n - i);
  }
  cout << (k < (1LL << 60) ? k : -1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(10);
  ;
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

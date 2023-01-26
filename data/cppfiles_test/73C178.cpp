#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(bool b) { cerr << b; }
void intext() {}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  vector<long long> a = v;
  sort(v.begin(), v.end());
  bool fg = 0;
  long long cnt = 0;
  while (a != v) {
    if (fg) {
      for (long long i = 1; i <= n - 2; i += 2)
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    } else {
      for (long long i = 0; i <= n - 3; i += 2)
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    fg ^= 1;
    cnt++;
  }
  cout << cnt << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  intext();
  long long t;
  cin >> t;
  while (t--) solve();
}

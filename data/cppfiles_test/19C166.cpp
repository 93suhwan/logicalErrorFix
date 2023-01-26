#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long long N = 1e3 + 10;
void run() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &e : a) cin >> e;
  map<long long, long long> cnt;
  for (long long i = 0; i < (1ll << n); i++) {
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      if (i & (1ll << j)) sum += a[j];
    }
    cnt[sum]++;
  }
  for (auto [f, s] : cnt) {
    if (s > 1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) run();
  return 0;
}

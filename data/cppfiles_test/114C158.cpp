#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 1e18;
const long long MAXN = 2e5 + 1;
const long long R = 1 << 20;
const long long mod = 1e9 + 7;
const long long LOGN = 21;
long long len(long long x) {
  long long cnt = 0;
  while (x > 0) {
    ++cnt;
    x /= 10;
  }
  return cnt;
}
long long res(long long a, long long b) {
  if (a > b) {
    cout << ">\n";
    return 1;
  }
  if (a < b) {
    cout << "<\n";
    return 1;
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  long long cnt = n / 2;
  for (long long i = n - 1; i >= 0 && cnt; --i) {
    cout << a[i] << " " << a[0] << "\n";
    --cnt;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}

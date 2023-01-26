#include <bits/stdc++.h>
using namespace std;
mt19937 Rand(time(0));
long long rnd(long long a) { return Rand() % a; }
long long rnd(long long a, long long b) { return Rand() % (b - a + 1) + a; }
double rnd_01d() { return (double)Rand() / (1ll << 32); }
double rnd_d(double r) { return rnd_01d() * r; }
const long long inf = 1e9 + 7;
void run() {
  long long n;
  cin >> n;
  vector<long long> h(n);
  for (long long i = 0; i < n; ++i) cin >> h[i];
  long long l = -1, r = 1e9 + 3;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    vector<long long> b;
    copy(begin(h), end(h), back_inserter(b));
    bool bad = false;
    for (long long i = n - 1; i >= 2; --i) {
      if (b[i] < mid) bad = true;
      long long d = min(b[i] - mid, h[i]) / 3;
      b[i - 1] += d;
      b[i - 2] += 2 * d;
    }
    if (b[1] < mid || b[0] < mid || bad)
      r = mid;
    else
      l = mid;
  }
  cout << l << endl;
}
signed main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  cout.precision(5);
  long long t = 1;
  cin >> t;
  while (t--) {
    run();
  }
}

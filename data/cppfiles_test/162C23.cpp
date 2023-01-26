#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const long long maxN = 2e5 + 10, oo = 1e9, MOD = 1e9 + 7;
using namespace std;
int n;
ll h[maxN], mx = 0, mn = oo + 1;
void readInput() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    mn = min(mn, h[i]);
    mx = max(mx, h[i]);
  }
}
ll res;
ll tmp[maxN];
bool check(ll x) {
  for (int i = 1; i <= n; ++i) tmp[i] = 0;
  for (int i = n; i >= 3; --i) {
    if (h[i] + tmp[i] < x) return 0;
    ll d = min(h[i] / 3, (h[i] + tmp[i] - x) / 3);
    tmp[i - 1] += d;
    tmp[i - 2] += 2 * d;
  }
  return (h[1] + tmp[1] >= x && h[2] + tmp[2] >= x);
}
void process() {
  ll l = mn, r = mx;
  res = mn;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (check(m)) {
      res = m;
      l = m + 1;
    } else
      r = m - 1;
  }
}
void writeOutput() { cout << res << '\n'; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    readInput();
    process();
    writeOutput();
  }
}

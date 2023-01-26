#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fxp(long long a, long long b) {
  assert(b >= 0);
  a %= mod;
  long long ans = 1;
  while (b > 0) {
    if (b % 2) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans % mod;
}
inline long long minv(long long x) { return fxp(x, mod - 2); }
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mXn = 2e5 + 4;
const long long inf = 1e18;
vector<int> ans;
int ck = 0;
void brute(int lev, int arem, int brem) {
  if (arem + brem == 0) {
    ans.push_back(ck);
    return;
  }
  if (arem) {
    if (lev == 1) ck++;
    brute(lev ^ 1, arem - 1, brem);
    if (lev == 1) ck--;
  }
  if (brem) {
    if (lev == 0) ck++;
    brute(lev ^ 1, arem, brem - 1);
    if (lev == 0) ck--;
  }
}
signed main() {
  c_p_c();
  int T;
  cin >> T;
  for (long long tc = 1; tc <= T; tc++) {
    int a, b;
    cin >> a >> b;
    int s = (a + b);
    pair<int, int> x[2];
    x[0] = {s / 2, s - s / 2};
    x[1] = {s - s / 2, s / 2};
    int mn = max(0, a - x[0].first) + max(0, b - x[0].second);
    mn = min(mn, max(0, a - x[1].first) + max(0, b - x[1].second));
    int mx = min(a, x[0].second) + min(b, x[0].first);
    mx = max(mx, min(a, x[1].second) + min(b, x[1].first));
    vector<int> bb;
    if (s % 2) {
      for (long long i = mn; i < mx + 1; i++) bb.push_back(i);
    } else {
      for (int i = mn; i <= mx; i += 2) bb.push_back(i);
    }
    cout << bb.size() << '\n';
    for (auto x : bb) cout << x << ' ';
    cout << '\n';
  }
}

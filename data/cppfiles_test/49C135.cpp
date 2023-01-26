#include <bits/stdc++.h>
using namespace std;
const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const long long INF = 2e18;
const int maxN = 5e5 + 1;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
inline int add(const int &a, const int &b) {
  return a + b >= md ? a + b - md : a + b;
}
inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline int mul(const int &a, const int &b) { return (1ll * a * b) % md; }
int binpow(int a, int b) {
  if (b <= 0) return 1;
  if (b % 2) return mul(a, binpow(a, b - 1));
  int m = binpow(a, b / 2);
  return mul(m, m);
}
int rev(int a) { return binpow(a, md - 2); }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  vector<vector<int>> prl(n, vector<int>(1 << n));
  for (int i = 0; i < (n); ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) {
        prl[i][mask] = 0;
        continue;
      }
      prl[i][mask] = 1;
      for (int j = 0; j < (n); ++j) {
        if ((1 << j) & mask) {
          prl[i][mask] = mul(prl[i][mask], mul(a[i], rev(add(a[i], a[j]))));
        }
      }
    }
  }
  vector<int> pw3(n + 1);
  pw3[0] = 1;
  for (int i = 1; i <= n; ++i) pw3[i] = pw3[i - 1] * 3;
  vector<int> dp(pw3[n]);
  vector<int> prwin(pw3[n]), prlose(pw3[n]);
  vector<int> to(1 << n);
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < (n); ++i) {
      if (mask & (1 << i)) to[mask] += pw3[i];
    }
  }
  for (int mask3 = 0; mask3 < (pw3[n]); ++mask3) {
    int mask1 = 0, mask2 = 0;
    {
      int c = mask3;
      for (int i = 0; i < (n); ++i) {
        int x = c % 3;
        c /= 3;
        if (x == 1) mask1 |= (1 << i);
        if (x == 2) mask2 |= (1 << i);
      }
    }
    prwin[mask3] = 1;
    prlose[mask3] = 1;
    for (int i = 0; i < (n); ++i) {
      if ((1 << i) & mask2) {
        prlose[mask3] = mul(prlose[mask3], prl[i][mask1]);
        prwin[mask3] = mul(prwin[mask3], sub(1, prl[i][mask1]));
      }
    }
  }
  for (int i = 0; i < (n); ++i) dp[pw3[i]] = 1;
  int ans = 0;
  for (int mask3 = 0; mask3 < (pw3[n]); ++mask3) {
    int mask1 = 0, mask2 = 0, mask0 = 0;
    {
      int c = mask3;
      for (int i = 0; i < (n); ++i) {
        int x = c % 3;
        c /= 3;
        if (x) mask1 |= (1 << i);
        if (x == 1) mask2 |= (1 << i);
        if (x == 0) mask0 |= (1 << i);
      }
    }
    for (int submask = mask0; submask > 0; submask = (submask - 1) & mask0) {
      int cur = dp[mask3];
      int nxt = to[mask1] * 2 + to[submask];
      cur = mul(cur, prwin[to[submask] * 2 + to[mask2]]);
      cur = mul(cur, prlose[to[submask] * 2 + to[mask1 ^ mask2]]);
      dp[nxt] = add(dp[nxt], cur);
    }
    if (!mask0) ans = add(ans, dp[mask3]);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  for (int _ = 0; _ < (tests); ++_) {
    solve();
  }
  return 0;
}

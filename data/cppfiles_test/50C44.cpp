#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
const int kN = 2e5 + 5;
const int kInf = 1e9 + 7;
const int P = 998244353;
int n, a[kN], lm[kN];
long long f[kN], s1[kN], s2[kN];
int sgn(int x) { return (x & 1) ? P - 1 : 1; }
void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  int minv = kInf;
  for (int i = mid; i >= l; --i) {
    minv = std::min(minv, a[i + 1]);
    s1[i] = f[i] * sgn(mid - i) % P * minv % P;
    s2[i] = f[i] * sgn(mid - i) % P;
    if (i < mid) {
      (s1[i] += s1[i + 1]) %= P;
      (s2[i] += s2[i + 1]) %= P;
    }
  }
  minv = kInf;
  int p = 0, lb = 0;
  for (int i = mid + 1; i <= r; ++i) {
    if (a[i] < minv) {
      minv = a[i];
      p = i;
    }
    lb = std::max(lm[p], l + 1);
    if (lb <= mid + 1) {
      (f[i] += s2[lb - 1] * minv % P * sgn(i - mid + 1)) %= P;
    }
    (f[i] += (s1[l] - s1[lb - 1] + P) * sgn(i - mid + 1) % P) %= P;
  }
  solve(mid + 1, r);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[lm[i] = i];
  for (int i = 1; i <= n; ++i) {
    while (lm[i] > 1 && a[lm[i] - 1] >= a[i]) lm[i] = lm[lm[i] - 1];
  }
  f[0] = 1;
  solve(0, n);
  printf("%lld", f[n]);
  return 0;
}

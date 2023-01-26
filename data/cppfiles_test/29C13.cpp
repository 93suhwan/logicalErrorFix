#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7, S = sqrt(N);
int mx = 0, Bs, B;
struct BLOCK {
  long long sum[N], val[N];
  inline void add(int x, int y) {
    int sy = (x + B - 1) / B;
    for (int i = (sy); i <= (Bs); ++i) sum[i] += y;
    for (int i = (x); i <= (min(sy * B, mx)); ++i) val[i] += y;
  }
  inline long long qzh(int x) { return x ? sum[(x - 1) / B] + val[x] : 0; }
  inline long long query(int l, int r) { return qzh(r) - qzh(l - 1); }
} bl1, bl2;
int n, a[N], p;
long long f[N];
inline long long calc1(int k) {
  long long res = 0;
  for (int l = 1, r; l <= k; l = r + 1)
    r = k / (k / l), res += (k / l) * bl2.query(l, r);
  return res;
}
inline long long calc2(int k) {
  long long res = 0;
  if (k <= B) return f[k];
  for (int i = (1); i <= (mx / k); ++i)
    res += i * bl1.query(i * k, min((i + 1) * k - 1, mx));
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long ns = 0, sum = 0;
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i], mx = max(mx, a[i]);
  B = sqrt(mx), Bs = (mx + B - 1) / B;
  for (int i = (1); i <= (n); ++i) {
    p = i, ns += (long long)a[i] * (i - 1) + sum;
    ns -= calc1(a[i]);
    ns -= calc2(a[i]) * a[i];
    cout << ns << " ";
    sum += a[i];
    bl1.add(a[i], 1), bl2.add(a[i], a[i]);
    for (int j = (1); j <= (B); ++j) f[j] += a[i] / j;
  }
  return 0;
}

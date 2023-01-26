#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n;
long long t[2 * 200010];
void build() {
  for (int i = n - 1; i > 0; --i) t[i] = gcd(t[i << 1], t[i << 1 | 1]);
}
void modify(int p, long long value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = gcd(t[p], t[p ^ 1]);
}
long long query(int l, int r) {
  long long res = 0;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = gcd(res, t[l++]);
    if (r & 1) res = gcd(res, t[--r]);
  }
  return res;
}
int bb(int i) {
  if (query(i, i) == 1) return 0;
  int l = i, r = n - 1;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (query(i, m) > 1) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l - i + 1;
}
void solve() {
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  n--;
  for (int i = 0; i < n; i++) t[n + i] = abs(a[i + 1] - a[i]);
  build();
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, bb(i));
  }
  cout << res + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tst;
  cin >> tst;
  while (tst--) solve();
  return 0;
}

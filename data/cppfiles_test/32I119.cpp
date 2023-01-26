#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[100005];
long long int mx[100005];
long long int seg[4 * 100005];
long long int sum[410];
void create() {
  freopen("Codeforces.inp", "w", stdout);
  srand(time(NULL));
}
void pretest() {
  sum[0] = 0;
  for (int i = 1; i <= 400; i++) sum[i] = sum[i - 1] + i;
}
void build(int l, int r, int id) {
  if (l == r) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, id * 2);
  build(mid + 1, r, id * 2 + 1);
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long int get(int l, int r, int u, int v, int id) {
  if (l > v || r < u) return 0;
  if (l >= u && r <= v) return seg[id];
  int mid = (l + r) / 2;
  return get(l, mid, u, v, id * 2) + get(mid + 1, r, u, v, id * 2 + 1);
}
void Solve() {
  cin >> n;
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) cin >> a[n - i + 1];
  for (int i = 1; i <= n; i++) {
    mx[i] = a[i];
    if (i != 1) mx[i] = max(mx[i], mx[i - 1]);
    ;
  }
  build(1, n, 1);
  int res = 1;
  for (int i = 2; i <= sqrt(2 * n); i++) {
    for (int j = n - i + 1; j >= sum[i - 1] + 1; j--) {
      long long int s = get(1, n, j, j + i - 1, 1);
      if (s < mx[j - 1]) {
        mx[j + i - 1] = mx[j - 1] + s;
        res = i;
      } else
        mx[j + i - 1] = -1e16 + 7;
    }
    for (int j = sum[i] + 1; j <= n - i - 1; j++) {
      mx[j] = max(mx[j], mx[j - 1]);
      ;
    }
  }
  cout << res << "\n";
}
int main() {
  pretest();
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}

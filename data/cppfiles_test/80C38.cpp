#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 3e6 + 10, M = 2 * N, mod = 998244353;
int n, m;
int a[N], b[N];
int ans[N];
void func(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = l + r >> 1;
  int Pos = L, Min = 1e9, first = 0, second = 0;
  for (int i = L; i <= R; i++) {
    if (b[mid] > a[i]) second++;
  }
  for (int i = L; i <= R; i++) {
    if (Min > first + second) {
      Min = first + second;
      Pos = i;
    }
    if (b[mid] < a[i]) first++;
    if (b[mid] > a[i]) second--;
  }
  ans[mid] = Pos;
  func(l, mid - 1, L, Pos), func(mid + 1, r, Pos, R);
}
int c[N], tmp[N];
long long acount;
void merge_sort(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  merge_sort(l, mid), merge_sort(mid + 1, r);
  for (int i = l, j = mid; i <= mid; i++) {
    while (j < r && c[j + 1] < c[i]) j++;
    acount += j - mid;
  }
  int i = l, j = mid + 1, cnt = 0;
  while (i <= mid && j <= r) {
    if (c[i] < c[j])
      tmp[++cnt] = c[i++];
    else
      tmp[++cnt] = c[j++];
  }
  while (i <= mid) tmp[++cnt] = c[i++];
  while (j <= r) tmp[++cnt] = c[j++];
  for (int i = l; i <= r; i++) c[i] = tmp[i - l + 1];
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  func(1, m, 1, n + 1);
  int cnt = 0, i, j;
  for (i = 1, j = 1; i <= m; i++) {
    while (j < ans[i]) c[++cnt] = a[j++];
    c[++cnt] = b[i];
  }
  while (j <= n) c[++cnt] = a[j++];
  acount = 0;
  merge_sort(1, cnt);
  cout << acount << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

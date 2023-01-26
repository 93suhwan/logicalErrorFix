#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1000000 + 10;
int n, m, a[N], b[N], p[N], c[N * 2], d[N * 2];
ll ans;
void divide(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) >> 1, cnt = 0, pos, mi = n + 2;
  for (int i = L; i <= R; i++) cnt += a[i] < b[mid];
  for (int i = L; i <= R; i++) {
    if (cnt < mi) {
      mi = cnt;
      pos = i;
    }
    if (a[i] > b[mid]) {
      cnt++;
    } else if (a[i] < b[mid]) {
      cnt--;
    }
  }
  p[mid] = pos;
  divide(l, mid - 1, L, pos);
  divide(mid + 1, r, pos, R);
}
void merge_sort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (c[i] <= c[j]) {
      d[k++] = c[i++];
    } else {
      ans += mid - i + 1;
      d[k++] = c[j++];
    }
  }
  while (i <= mid) d[k++] = c[i++];
  while (j <= r) d[k++] = c[j++];
  for (int i = l; i <= r; i++) c[i] = d[i];
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + 1 + m);
    divide(1, m, 1, n + 1);
    for (int i = 1, j = 1, k = 1; i <= n + 1; i++) {
      while (j <= m && p[j] == i) c[k++] = b[j++];
      if (i <= n) c[k++] = a[i];
    }
    ans = 0;
    merge_sort(1, n + m);
    cout << ans << '\n';
  }
  return 0;
}

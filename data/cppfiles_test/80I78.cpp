#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int p[MAXN], a[MAXN], b[MAXN], t, n, m;
long long solve(int li, int ri, int lp, int rp) {
  if (li >= ri) {
    return 0;
  }
  int mid = (li + ri) >> 1;
  long long res = 0;
  for (int i = lp; i < rp; i++) {
    if (a[i] < b[mid]) res++;
  }
  int pos = lp;
  long long mn = res;
  for (int i = lp + 1; i <= rp; i++) {
    if (a[i - 1] < b[mid]) res--;
    if (a[i - 1] > b[mid]) res++;
    if (res < mn) {
      mn = res;
      pos = i;
    }
  }
  return mn + solve(li, mid, lp, pos) + solve(mid + 1, ri, pos, rp);
}
long long invs(int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  long long res = invs(l, mid) + invs(mid + 1, r);
  long long cnt = 0;
  for (int i = l, j = mid + 1; i <= mid; i++) {
    while (j <= r && a[i] > a[j]) {
      cnt++;
      j++;
    }
    res += cnt;
  }
  sort(a + l, a + r + 1);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + 1 + m);
    cout << solve(1, m + 1, 1, n + 1) + invs(1, n) << '\n';
  }
  return 0;
}

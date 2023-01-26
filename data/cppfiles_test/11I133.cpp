#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (c < '0') f |= (c == '-'), c = getchar();
  while (c >= '0') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
int Ans, n, a[500005], ans[500005], o[500005], cnt, b[500005];
void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid + 1, r);
  int ma = 0, j = mid + 1, s = 0;
  for (int i = l; i <= mid; i++) {
    while (j <= r && a[b[j]] < a[b[i]]) ans[b[j]] = ma + 1, o[s++] = b[j++];
    ma = max(ans[b[i]], ma);
    o[s++] = b[i];
  }
  while (j <= r) ans[b[j]] = ma + 1, o[s++] = b[j++];
  for (int i = 0; i < s; i++) b[i + l] = o[i];
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] <= i) b[++cnt] = i;
  }
  sort(b + 1, b + cnt + 1, [](int x, int y) {
    if (x - a[x] == y - a[y]) return a[x] < a[y];
    return x - a[x] < y - a[y];
  });
  solve(1, cnt);
  for (int i = 1; i <= n; i++) Ans = max(Ans, ans[i] + 1);
  cout << Ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
int n;
int a[N];
int maxu[N * 10];
void ubd(int tl, int tr, int x, int y, int pos) {
  if (tl == tr) {
    maxu[pos] = max(maxu[pos], y);
    return;
  }
  int m = (tl + tr) / 2;
  if (x <= m)
    ubd(tl, m, x, y, pos * 2);
  else
    ubd(m + 1, tr, x, y, pos * 2 + 1);
  maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos) {
  if (l > r) return -N;
  if (tl == l && tr == r) return maxu[pos];
  int m = (tl + tr) / 2;
  return max(qry(tl, m, l, min(m, r), pos * 2),
             qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}
void solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) a[i] -= i;
  for (int i = 0; i < N * 10; ++i) maxu[i] = -N;
  ubd(0, N * 2, N + 0, 0, 1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] < 0) continue;
    ubd(0, N * 2, N + a[i] - i, qry(0, N * 2, N + a[i] - i + 1, N * 2, 1) + 1,
        1);
  }
  cout << maxu[1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) solv();
  return 0;
}

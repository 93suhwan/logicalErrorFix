#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7, N = 2e5 + 10;
const int M = 400;
int st[N];
int seg[M][M];
int strt[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<array<int, 2>> a(n);
  for (int i = 0, x, y; i < n; ++i) {
    cin >> x >> y;
    a[i] = {x, y};
  }
  auto update = [&](int x, int y, int inc) {
    st[x] += inc;
    st[y + 1] -= inc;
  };
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (i) st[i] += st[i - 1];
    int op, k;
    cin >> op >> k;
    --k;
    auto [x, y] = a[k];
    int inc = (op == 1 ? 1 : -1);
    if (op == 1) {
      strt[k] = i;
    }
    int s = x + y;
    if (x + y < M) {
      for (int j = strt[k] + x; j < strt[k] + x + y; ++j) {
        seg[s][j % s] += inc;
      }
    } else {
      for (int j = strt[k] + x; j < m; j += s) {
        if (j > i) {
          st[j] += inc;
          st[min(j + y, m)] -= inc;
        }
        if (j <= i and j + y - 1 >= i) {
          st[i] += inc;
          st[min(j + y, m)] -= inc;
        }
      }
    }
    int ans = st[i];
    for (int j = 2; j < M; ++j) {
      ans += seg[j][i % j];
    }
    cout << ans << '\n';
  }
  return 0;
}

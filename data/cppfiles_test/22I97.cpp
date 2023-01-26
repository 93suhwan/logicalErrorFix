#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
const int N = 998244, M = 1001;
int n, m, d[N], las[N], seq[M], cnt[M][M], blo, x[N], y[N];
inline void add(int a, int b, int val) { seq[a] += val, seq[b + 1] -= val; }
signed main() {
  std::ios::sync_with_stdio(0);
  cin >> n >> m;
  blo = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  int op, k;
  for (int now = 1; now <= m; now++) {
    cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] <= blo) {
        for (int i = x[k]; i < x[k] + y[k]; i++)
          cnt[x[k] + y[k]][(now + i) % (x[k] + y[k])]++;
      } else
        for (int i = now + x[k]; i <= n; i += x[k] + y[k])
          add(i, i + y[k] - 1, 1);
      las[k] = now;
    } else {
      if (x[k] + y[k] <= blo) {
        for (int i = x[k]; i < x[k] + y[k]; i++)
          cnt[x[k] + y[k]][(las[k] + i) % (x[k] + y[k])]--;
      } else
        for (int i = las[k] + x[k]; i <= n; i += x[k] + y[k])
          add(std::max(now, i), std::max(now, i + y[k] - 1), -1);
    }
    int ans = 0;
    for (int i = 2; i <= blo; i++) {
      ans += cnt[i][now % i];
    }
    seq[now] += seq[now - 1];
    cout << ans + seq[now] << "\n";
  }
}

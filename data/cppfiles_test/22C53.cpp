#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 228;
const int M = 500;
int n, m, a[N], b[N];
struct event {
  int op, k;
} f[N];
queue<pair<int, int> > actions[N];
int _____________prev[N], cur[N], nxt[N];
int sum[N], cnt[500][500];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int i = 1; i <= m; ++i) nxt[i] = m + 1;
  for (int i = 1; i <= m; ++i) {
    cin >> f[i].op >> f[i].k;
    if (f[i].op == 1)
      cur[f[i].k] = i;
    else {
      nxt[cur[f[i].k]] = i;
      _____________prev[i] = cur[f[i].k];
    }
  }
  int S = (int)sqrt(m);
  for (int i = 1; i <= m; ++i) {
    if (f[i].op == 1) {
      if (a[f[i].k] + b[f[i].k] > S) {
        int x = a[f[i].k], y = b[f[i].k];
        for (int j = i; j < nxt[i]; j += x + y) {
          if (j + x < nxt[i]) {
            sum[j + x]++;
            sum[min(j + x + y, nxt[i])]--;
          }
        }
      } else {
        int x = a[f[i].k], y = b[f[i].k];
        int c = i % (x + y);
        for (int r = 0; r < x + y; ++r) {
          if ((r - c + x + y) % (x + y) >= x) cnt[x + y][r]++;
        }
      }
    } else {
      int x = a[f[i].k], y = b[f[i].k];
      int c = _____________prev[i] % (x + y);
      if (x + y <= S) {
        for (int r = 0; r < x + y; ++r) {
          if ((r - c + x + y) % (x + y) >= x) cnt[x + y][r]--;
        }
      }
    }
    sum[i] += sum[i - 1];
    int res = sum[i];
    for (int k = 2; k <= S; ++k) res += cnt[k][i % k];
    cout << res << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

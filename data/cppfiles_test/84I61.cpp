#include <bits/stdc++.h>
using namespace std;
const int N = 100005, B = 18;
long long f[B][N];
int p[N], s, phi[N];
bool np[N];
vector<pair<int, int>> v[N];
namespace sgt {
long long mn[N << 2], lazy[N << 2];
void build(int i, int l, int r, long long *f) {
  mn[i] = f[l], lazy[i] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(i << 1, l, mid, f), build(i << 1 | 1, mid + 1, r, f);
}
void modify(int i, int l, int r, int x, int y) {
  if (x >= r) {
    mn[i] += y, lazy[i] += y;
    return;
  }
  int mid = (l + r) >> 1;
  modify(i << 1, l, mid, x, y);
  if (x > mid) modify(i << 1 | 1, mid + 1, r, x, y);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]) + lazy[i];
}
}  // namespace sgt
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n = 100000;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) {
      p[++s] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= s && i * p[j] <= n; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i] = phi[i] * (p[j] - 1);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) v[j].push_back(make_pair(i, phi[j / i]));
  for (int i = 1; i <= n; i++) f[0][i] = 1 << 30;
  for (int t = 1; t < B; t++) {
    sgt::build(1, 0, n, f[t - 1]);
    for (int i = 1; i <= n; i++) {
      for (auto tp : v[i]) sgt::modify(1, 0, n, tp.first - 1, tp.second);
      f[t][i] = sgt::mn[1];
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> k;
    if (k >= B)
      cout << n << '\n';
    else
      cout << f[k][n] << '\n';
  }
}

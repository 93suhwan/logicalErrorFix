#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, M = 2 * N, mod = 1e9 + 7;
int n;
int a[N], b[N], c[N];
long long s[N], ans[N], res;
int fa[N], siz[N];
pair<int, int> p[N];
struct Query {
  int id, k;
} q[N];
int find(int first) {
  if (fa[first] != first) fa[first] = find(fa[first]);
  return fa[first];
}
void merge(int first) {
  auto &[d, pos] = p[first];
  int pa = find(pos), push_back = find(pos + 1);
  res -= s[pa] - s[pa - siz[pa]] + s[push_back] - s[push_back - siz[push_back]];
  siz[push_back] += siz[pa];
  fa[pa] = push_back;
  res += s[push_back] - s[push_back - siz[push_back]];
}
void solve() {
  int n, m, Q;
  cin >> n >> m >> Q;
  for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i], res += a[i];
  for (int i = 1; i <= m; i++) cin >> b[i], c[i + n] = b[i];
  sort(a + 1, a + n + 1);
  sort(c + 1, c + n + m + 1);
  for (int i = 1; i < n + m; i++) {
    p[i] = {c[i + 1] - c[i], i};
  }
  for (int i = 1, j = 1; i <= n + m; i++) {
    fa[i] = i;
    if (j <= n && c[i] == a[j]) {
      siz[i] = 1;
      j++;
    }
  }
  sort(p + 1, p + n + m);
  for (int i = 1; i <= Q; i++) {
    int k;
    cin >> k;
    q[i] = {i, k};
  }
  sort(q + 1, q + Q + 1, [&](Query a, Query b) { return a.k < b.k; });
  for (int i = 1; i <= n + m; i++) s[i] = s[i - 1] + c[i];
  for (int i = 1, pos = 0; i <= Q; i++) {
    auto &[id, k] = q[i];
    while (pos < n + m - 1 && p[pos + 1].first <= k) merge(++pos);
    ans[id] = res;
  }
  for (int i = 1; i <= Q; i++) cout << ans[i] << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cout.precision(2), cout.setf(ios::fixed);
  solve();
  return 0;
}

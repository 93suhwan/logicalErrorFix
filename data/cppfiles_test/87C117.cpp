#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
namespace Acc {
const int N = 3e2 + 9;
int a[N], ord[N], t[N], b[N], n;
void add(int x) {
  for (; x <= n; x += x & -x) ++t[x];
}
int ask(int x) {
  int r = 0;
  for (; x; x -= x & -x) r += t[x];
  return r;
}
void work() {
  int m, i, x, z = 0;
  for (cin >> m >> n, i = 1; i <= n; ++i) cin >> a[i], t[i] = 0;
  iota(ord, ord + n + 1, 0), sort(ord + 1, ord + n + 1, [](int x, int y) {
    return a[x] < a[y] || a[x] == a[y] && x > y;
  });
  for (i = 1; i <= n; ++i) b[ord[i]] = i;
  for (i = 1; i <= n; ++i) z += ask(b[i]), add(b[i]);
  cout << z << '\n';
}
}  // namespace Acc
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  for (cin >> T; T--;) Acc::work();
}

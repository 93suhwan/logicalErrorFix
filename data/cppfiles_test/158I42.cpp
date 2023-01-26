#include <bits/stdc++.h>
using namespace std;
const int N = 11, M = 1e4 + 5;
int n, m, p[M];
long long res = 0;
struct Student {
  int p, q[M];
} a[N];
struct Problem {
  int cnt, id;
} b[M];
bool cmp(Problem a, Problem b) { return a.cnt < b.cnt; }
int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].p);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) scanf("%1d", &a[i].q[j]);
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 1; j <= m; ++j) {
      b[j].id = j, b[j].cnt = 0;
      for (int k = 0; k < n; ++k)
        b[j].cnt += a[k + 1].q[j] * (((i >> k) & 1) ? 1 : -1);
    }
    sort(b + 1, b + 1 + m, cmp);
    long long sum = 0;
    for (int j = 0; j < n; ++j) sum += a[j + 1].p * (((i >> j) & 1) ? -1 : 1);
    for (int j = 1; j <= m; ++j) sum += b[j].cnt * j;
    if (sum > res)
      for (int j = 1; j <= m; ++j) p[b[j].id] = j;
  }
  for (int i = 1; i <= m; ++i) printf("%d ", p[i]);
  return printf("\n"), 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}

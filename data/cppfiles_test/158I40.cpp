#include <bits/stdc++.h>
using namespace std;
const int N = 11, M = 1e4 + 5;
int n, m, res[M], now;
struct Student {
  int p, q[M];
} a[N];
bool cmp(Student a, Student b) { return a.p < b.p; }
struct Data {
  int id, data;
} b[M];
bool CMP(Data a, Data b) { return a.data < b.data; }
int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].p);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) scanf("%1d", &a[i].q[j]);
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= m; ++i) {
    b[i].id = i;
    for (int j = 0; j < n; ++j) b[i].data += (a[j + 1].q[i] << j);
  }
  now = m;
  for (int i = 1; i <= m; ++i) res[i] = 0;
  for (int i = 1; i <= n; ++i) {
    sort(b + 1, b + 1 + m, CMP);
    for (int j = 1; j <= m; ++j) {
      if (b[j].data & 1)
        res[b[j].id] = now--, b[j].data = 0;
      else
        b[j].data >>= 1;
    }
  }
  for (int i = 1; i <= m; ++i)
    if (!res[i]) res[i] = now--;
  for (int i = 1; i <= m; ++i) printf("%d ", res[i]);
  return printf("\n"), 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}

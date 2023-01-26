#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 1010;
bool M[MAXN][MAXN];
void solve() {
  int n;
  dadsadasda = scanf("%d", &n);
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) M[i][j] = 0;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) dadsadasda = scanf("%d %d", &l[i], &r[i]);
  for (int i = 0; i < n; i++) M[l[i]][r[i]] = 1;
  for (int i = 0; i < n; i++) {
    if (l[i] == r[i]) {
      printf("%d %d %d\n", l[i], r[i], l[i]);
      continue;
    }
    for (int j = 0; j < n; j++)
      if (i != j) {
        if (l[i] == l[j] && r[i] == r[j] + 1) {
          printf("%d %d %d\n", l[i], r[i], r[i]);
          break;
        }
        if (l[i] + 1 == l[j] && r[i] == r[j]) {
          printf("%d %d %d\n", l[i], r[i], l[i]);
          break;
        }
        if (l[i] == l[j] && r[i] > r[j] && M[r[j] + 2][r[i]]) {
          printf("%d %d %d\n", l[i], r[i], r[j] + 1);
          break;
        }
        assert(j + 1 != n);
      }
  }
}
int main() {
  int t;
  dadsadasda = scanf("%d", &t);
  while (t--) solve();
  return 0;
}

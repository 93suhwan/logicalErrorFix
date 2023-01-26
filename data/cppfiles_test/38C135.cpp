#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<char> a[N];
vector<int> w;
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  w.resize(m + 1);
  for (register int i = 1; i <= n; i++) {
    a[i].resize(m + 1);
    getchar();
    for (register int j = 1; j <= m; j++) a[i][j] = getchar();
  }
  for (register int i = 2; i <= n; i++)
    for (register int j = 2; j <= m; j++)
      if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') w[j] = 1;
  for (register int i = 1; i <= m; i++) w[i] += w[i - 1];
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (w[r] - w[l] > 0)
      puts("NO");
    else
      puts("YES");
  }
}
int main() {
  solve();
  return 0;
}

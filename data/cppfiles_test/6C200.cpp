#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int gra[maxn];
int main() {
  if (fopen("yl.in", "r")) {
    freopen("yl.in", "r", stdin);
    freopen("yl.out", "w", stdout);
  }
  int n, m, u, v, cnt = 0;
  cin >> n >> m;
  for (int i = (1); i <= (m); ++i) {
    cin >> u >> v;
    ++gra[min(u, v)];
  }
  for (int i = (1); i <= (n); ++i) {
    if (!gra[i]) ++cnt;
  }
  int q, opt;
  cin >> q;
  for (int qr = (1); qr <= (q); ++qr) {
    cin >> opt;
    if (opt == 3) {
      cout << cnt << endl;
      continue;
    }
    cin >> u >> v;
    if (opt == 1) {
      if (gra[min(u, v)]++ == 0) --cnt;
    } else {
      if (--gra[min(u, v)] == 0) ++cnt;
    }
  }
  return 0;
}

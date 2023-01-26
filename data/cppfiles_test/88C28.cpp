#include <bits/stdc++.h>
using namespace std;
void run() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
const long long N = 1e6 + 10;
long long ptoc[N];
long long c[N];
long long n, m;
struct Node {
  long long x, y;
  bool operator<(const Node& oth) const {
    if (x != oth.x) return x < oth.x;
    return y > oth.y;
  }
} topos[N];
map<long long, set<Node>> cpos;
long long has[400][400];
signed main() {
  run();
  long long z;
  cin >> z;
  while (z--) {
    cin >> n >> m;
    long long tot = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        tot++;
        topos[tot].x = i;
        topos[tot].y = j;
      }
    }
    for (long long i = 1; i <= n * m; i++) {
      cin >> ptoc[i];
      c[i] = ptoc[i];
      cpos[c[i]].clear();
      long long x, y;
      x = topos[i].x;
      y = topos[i].y;
      has[x][y] = 0;
    }
    sort(c + 1, c + m * n + 1);
    for (long long i = 1; i <= n * m; i++) {
      long long x, y;
      x = topos[i].x;
      y = topos[i].y;
      cpos[c[i]].insert((Node){x, y});
    }
    long long ans = 0;
    for (long long i = 1; i <= n * m; i++) {
      Node pos;
      auto it = cpos[ptoc[i]].begin();
      pos = *it;
      cpos[ptoc[i]].erase(it);
      for (long long j = 1; j <= pos.y; j++) {
        if (has[pos.x][j]) ans++;
      }
      has[pos.x][pos.y] = 1;
    }
    cout << ans << endl;
  }
  return 0;
}

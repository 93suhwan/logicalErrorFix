#include <bits/stdc++.h>
using namespace std;
long long n, m, N, Left, Right;
long long node = 0;
long long seg[2000001], vs[2000001];
long long dx[] = {1, 0};
long long dy[] = {0, 1};
long long Query(long long l = 1, long long r = N, long long index = 1) {
  if (l > Right || r < Left) return 0;
  if (l >= Left && r <= Right) return seg[index];
  long long mid = (l + r) / 2;
  return max(Query(l, mid, index * 2), Query(mid + 1, r, index * 2 + 1));
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  char grid[n + 1][m + 1];
  long long vs[n + 1][m + 1];
  set<pair<long long, long long>> d;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> grid[i][j];
      d.insert({i, j});
      vs[i][j] = 1e18;
    }
  }
  while (d.size()) {
    auto cur = *d.begin();
    d.erase(d.begin());
    if (grid[cur.first][cur.second] == 'X') continue;
    vs[cur.first][cur.second] = min(vs[cur.first][cur.second], cur.second);
    for (long long i = 0; i < 2; i++) {
      long long aa = cur.first + dx[i], bb = cur.second + dy[i];
      if (aa < 1 || bb < 1 || aa > n || bb > m || grid[aa][bb] == 'X' ||
          (cur.first > aa) || (cur.second) > bb)
        continue;
      if (vs[cur.first][cur.second] < vs[aa][bb]) {
        vs[aa][bb] = vs[cur.first][cur.second];
        d.insert({aa, bb});
      }
    }
  }
  N = exp2(ceil(log2(m)));
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      if (vs[j][i] == 1e18) vs[j][i] = -1;
      seg[i + N - 1] = max(vs[j][i], seg[i + N - 1]);
    }
  }
  for (long long i = N - 1; i > 0; i--) {
    seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
  }
  long long q;
  cin >> q;
  while (q--) {
    cin >> Left >> Right;
    long long ans = Query();
    cout << (ans <= Left ? "YES" : "NO") << '\n';
  }
  return 0;
}

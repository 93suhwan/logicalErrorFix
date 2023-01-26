#include <bits/stdc++.h>
using namespace std;
long long T, n, m, ans, sumb, a[2005], b[2005], tu[4005], tv[4005];
long long vis[2005], mer[2005], lis[8005], pre[2005], las[2005], lisc = 0;
long long ec, hed[2005], nxt[8005], to[8005];
void add_edge(long long f, long long t) {
  ++ec;
  to[ec] = t;
  nxt[ec] = hed[f];
  hed[f] = ec;
}
struct node {
  long long x, v;
} t;
queue<node> q;
long long bfs(long long x) {
  for (long long i = 1; i <= n; i++) vis[i] = 0;
  vis[1] = 1;
  pre[1] = 1;
  while (!q.empty()) q.pop();
  t.x = 1;
  t.v = x;
  q.push(t);
  while (!q.empty()) {
    long long u, v, now;
    node h = q.front();
    q.pop();
    u = h.x;
    for (long long i = hed[u]; i; i = nxt[i]) {
      v = to[i];
      if (las[u] == (i ^ 1)) continue;
      if (vis[v]) {
        lisc = 0;
        now = u;
        while (1) {
          if (now == 1) break;
          lis[++lisc] = now;
          now = pre[now];
        }
        now = v;
        while (1) {
          if (now == 1) break;
          lis[++lisc] = now;
          now = pre[now];
        }
        return 1;
      }
      if (a[v] < h.v) {
        pre[v] = u;
        las[v] = i;
        vis[v] = 1;
        t.x = v;
        t.v = h.v + b[v];
        q.push(t);
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ans = 0;
    sumb = 0;
    a[1] = 0;
    for (long long i = 2; i <= n; i++) cin >> a[i];
    b[1] = 0;
    for (long long i = 2; i <= n; i++) cin >> b[i];
    for (long long i = 1; i <= n; i++) mer[i] = 0;
    for (long long i = 1; i <= m; i++) cin >> tu[i] >> tv[i];
    mer[1] = 1;
    for (long long l, r, mid, tmp, cnt = n, i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) hed[j] = 0;
      ec = 1;
      for (long long u, v, j = 1; j <= m; j++) {
        u = tu[j];
        v = tv[j];
        if (mer[u]) u = 1;
        if (mer[v]) v = 1;
        if (u != v) {
          add_edge(u, v);
          add_edge(v, u);
        }
      }
      l = ans;
      tmp = r = 1000000001;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (bfs(mid + sumb)) {
          tmp = mid;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      for (long long j = 1; j <= lisc; j++) {
        if (!mer[lis[j]]) cnt--, sumb += b[lis[j]];
        mer[lis[j]] = 1;
      }
      ans = tmp;
      if (cnt == 1) break;
    }
    cout << ans << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T s = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + (c ^ 48);
    c = getchar();
  }
  return s * w;
}
template <class T>
inline bool chkmax(T& x, const T& y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T& x, const T& y) {
  return x > y ? x = y, true : false;
}
const long long maxn = 303030;
const long long maxm = 404040;
vector<long long> G[maxn];
long long a[maxn], b[maxn];
long long l, r;
long long n, m;
long long vis[maxn], pre[maxn];
long long check(long long mid) {
  long long power = mid;
  for (long long i = 1; i <= n; i++) vis[i] = 0;
  vector<long long> st;
  st.push_back(1);
  vis[1] = 1;
  while (st.size() != n) {
    queue<pair<long long, long long> > q;
    for (long long v : st) q.push(make_pair(-v, power));
    for (long long i = 1; i <= n; i++) pre[i] = 0;
    long long s = 0, t = 0;
    while (!q.empty()) {
      pair<long long, long long> u = q.front();
      q.pop();
      long long flag = u.first > 0;
      u.first = abs(u.first);
      long long x = u.first;
      for (long long v : G[u.first]) {
        if (pre[x] == v || a[v] >= u.second) continue;
        if (pre[v] || (vis[v] && flag)) {
          s = x, t = v;
          break;
        }
        if (vis[v]) continue;
        pre[v] = x;
        q.push(make_pair(v, u.second + b[v]));
      }
      if (s && t) break;
    }
    if (!s && !t) break;
    do {
      if (!vis[s]) {
        st.push_back(s);
        vis[s] = 1;
        power += b[s];
      }
    } while (s = pre[s]);
    do {
      if (!vis[t]) {
        st.push_back(t);
        vis[t] = 1;
        power += b[t];
      }
    } while (t = pre[t]);
  }
  if (st.size() == n)
    return 1;
  else
    return 0;
}
signed main() {
  long long T = read<long long>();
  while (T--) {
    l = 1, r = 0;
    n = read<long long>(), m = read<long long>();
    for (long long i = 1; i <= n; i++) G[i].clear();
    for (long long i = 2; i <= n; i++)
      a[i] = read<long long>(), chkmax(r, a[i]);
    for (long long i = 2; i <= n; i++) b[i] = read<long long>();
    r = r + 1;
    for (long long i = 1; i <= m; i++) {
      long long x = read<long long>(), y = read<long long>();
      G[x].push_back(y);
      G[y].push_back(x);
    }
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}

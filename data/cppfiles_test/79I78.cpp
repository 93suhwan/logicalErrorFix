#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ret = 0, t = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') t = -1, c = getchar();
  while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
  return ret * t;
}
const int MAXN = 300300 << 3;
int n, a[MAXN], b[MAXN];
vector<pair<int, int> > E[MAXN];
struct seg {
  int ls, rs;
} t[MAXN];
int top;
void build(int l, int r, int x) {
  if (l == r) {
    E[x].push_back(make_pair(l == 0 ? 0 : (l + n), 0));
    return;
  }
  t[x].ls = ++top, t[x].rs = ++top;
  int mid = (l + r) >> 1;
  E[x].push_back(make_pair(t[x].ls, 0)), E[x].push_back(make_pair(t[x].rs, 0));
  build(l, mid, t[x].ls), build(mid + 1, r, t[x].rs);
}
void con(int first, int l, int r, int L, int R, int x) {
  if (l <= L && R <= r) {
    E[first].push_back(make_pair(x, 1));
    return;
  }
  int mid = (L + R) >> 1;
  if (l <= mid) con(first, l, r, L, mid, t[x].ls);
  if (mid < r) con(first, l, r, mid + 1, R, t[x].rs);
}
const int inf = 0x3f3f3f3f;
deque<int> dq;
int dis[MAXN], FR[MAXN];
bool vis[MAXN];
vector<int> v;
void out(int x) {
  if (x != n) out(FR[x]);
  if (x <= 2 * n) v.push_back(x);
}
int main() {
  n = read();
  int i, j;
  top = n * 2;
  int rt = top + 1;
  build(0, n, ++top);
  for (i = 1; i <= n; i++) a[i] = read(), con(i, i - a[i], i, 0, n, rt);
  for (i = 1; i <= n; i++)
    b[i] = read(), E[i + n].push_back(make_pair(i + b[i], 0));
  memset(dis, 0x3f, sizeof dis);
  dis[n] = 0;
  dq.push_back(n);
  while (!dq.empty()) {
    int x = dq.front();
    dq.pop_front();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto i : E[x])
      if (dis[i.first] > dis[x] + i.second) {
        dis[i.first] = dis[x] + i.second;
        FR[i.first] = x;
        if (i.second)
          dq.push_back(i.first);
        else
          dq.push_front(i.first);
      }
  }
  if (dis[0] == inf) {
    puts("-1");
    return 0;
  }
  out(0);
  printf("%d\n", dis[0] == inf ? -1 : dis[0]);
  for (int i = 0; i < v.size(); i++)
    if (v[i] <= n && v[i])
      printf("%d ", v[i] - (v[i + 1] - (v[i + 1] ? n : 0)));
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int p1 = 1000000, p2 = 0;
char buf[1000005], wb[1000005];
int gc() {
  if (p1 >= 1000000) fread(buf, 1, 1000000, stdin), p1 = 0;
  return buf[p1++];
}
long long getint() {
  long long ret = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
  }
  return ret * flag;
}
void pc(char x) {
  if (p2 >= 1000000) fwrite(wb, 1, 1000000, stdout), p2 = 0;
  wb[p2++] = x;
}
void wrt(long long x) {
  if (x < 0) pc('-'), x = -x;
  int c[24] = {0};
  if (!x) return pc('0'), void();
  while (x) c[++c[0]] = x % 10, x /= 10;
  while (c[0]) pc(c[c[0]--] + '0');
}
const int base = (1 << 10) - 1, inf = 0x3f3f3f3f;
int n, m;
long long a[1005], ans[1005];
int mk(int x, int y) { return x << 10 | y; }
const int S = 1003, T = 1004;
struct edge {
  int ne, v, p;
} e[2005];
int head[1005], cnt;
void add(int u, int v, int p) {
  ++cnt, e[cnt].v = v, e[cnt].ne = head[u], head[u] = cnt, e[cnt].p = p;
  ++cnt, e[cnt].v = u, e[cnt].ne = head[v], head[v] = cnt, e[cnt].p = 0;
}
int dis[1005], gap[1005], tot;
int DFS(int x, int maxf) {
  if (x == T) return maxf;
  int ret = 0;
  for (int i = head[x]; i; i = e[i].ne) {
    int y = e[i].v;
    if (e[i].p && dis[y] + 1 == dis[x]) {
      int dlt = DFS(y, min(e[i].p, maxf));
      e[i].p -= dlt, e[i ^ 1].p += dlt;
      maxf -= dlt, ret += dlt;
      if (!maxf || dis[S] > tot) return ret;
    }
  }
  if (!--gap[dis[x]]) dis[S] = tot;
  return gap[++dis[x]]++, ret;
}
int SAP() {
  for (int i = 1; i <= tot; i++) gap[i] = 0;
  gap[0] = tot;
  int ret = 0;
  while (dis[S] < tot) ret += DFS(S, 1 << 30);
  return ret;
}
bool cut[1005];
void dfs(int x) {
  if (cut[x]) return;
  cut[x] = 1;
  for (int i = head[x]; i; i = e[i].ne)
    if (e[i].p) dfs(e[i].v);
}
void rebuild(vector<int> &p, vector<int> &e, long long mid) {
  int res = 0;
  for (int i : p)
    cut[i] = 0, ++tot, a[i] > mid ? res += 1, add(S, i, 1) : add(i, T, 1);
  for (int i : e) add(i >> 10, i & base, inf);
  res -= SAP();
  dfs(S), tot = 0, cnt = 1;
  for (int i : p) dis[i] = head[i] = 0;
  head[S] = head[T] = cut[S] = cut[T] = dis[S] = dis[T] = 0;
}
void solve(vector<int> &p, vector<int> &e, long long l, long long r) {
  if (l == r || p.empty()) {
    for (int i : p) ans[i] = l;
    return;
  }
  vector<int> vl, vr, X, Y;
  long long mid = (l + r) >> 1;
  rebuild(p, e, mid);
  for (int i : p) !cut[i] ? vl.push_back(i) : vr.push_back(i);
  for (int val : e) {
    int x = val >> 10, y = val & base;
    if (cut[x] ^ cut[y]) continue;
    !cut[x] ? X.push_back(val) : Y.push_back(val);
  }
  solve(vl, X, l, mid), solve(vr, Y, mid + 1, r);
}
int main() {
  n = getint(), m = getint();
  vector<int> vec, id;
  for (int i = 1; i <= n; i++) a[i] = getint(), id.push_back(i);
  for (int i = 1; i <= m; i++) {
    int x = getint(), y = getint();
    vec.push_back(mk(x, y));
  }
  solve(id, vec, -1e15, 1e15);
  for (int i = 1; i <= n; i++) wrt(ans[i]), pc(' ');
  long long s = 0;
  for (int i = 1; i <= n; i++) s += abs(ans[i] - a[i]);
  fwrite(wb, 1, p2, stdout);
  return true xor true;
}

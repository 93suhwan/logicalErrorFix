#include <bits/stdc++.h>
using namespace std;
int read() {
  int a = 0;
  int f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
const int INF = 998244353;
int T;
int n;
long long ans;
int val[1000050];
char s[1000050];
int pre[1000050];
bool vis[1000050];
int t[1000050], top;
int sum[1000050];
int pos[1000050];
vector<pair<int, int> > q[1000050];
int bl[4000050];
void init() {
  for (int i = 1; i <= n * 4; ++i) bl[i] = n + 1;
  for (int i = 2; i <= 1000000; ++i) {
    if (!vis[i]) pre[i] = i, t[++top] = i;
    for (int j = 1; j <= top && i * t[j] <= 1000000; ++j) {
      vis[i * t[j]] = true;
      pre[i * t[j]] = t[j];
    }
  }
}
void modify(int u, int l, int r, int L, int R, int V) {
  if (L <= l && r <= R) {
    bl[u] = min(bl[u], V);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) modify(u << 1, l, mid, L, R, V);
  if (R > mid) modify(u << 1 | 1, mid + 1, r, L, R, V);
}
void calc(int u, int l, int r, int v) {
  v = min(v, bl[u]);
  if (l == r) {
    ans += v - l;
    return;
  }
  int mid = (l + r) >> 1;
  calc(u << 1, l, mid, v);
  calc(u << 1 | 1, mid + 1, r, v);
}
int main() {
  n = read();
  init();
  for (int i = 1; i <= n; ++i) val[i] = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    int tmp = val[i];
    while (tmp != 1) {
      int now = pre[tmp];
      int cnt = 0;
      while (pre[tmp] == now) tmp /= now, cnt++;
      if (s[i] == '/') cnt = -cnt;
      q[now].push_back({i, cnt});
    }
  }
  for (int k = 2; k <= 1000000; ++k) {
    if (vis[k]) continue;
    int m = q[k].size();
    if (!m) continue;
    for (int i = 1; i <= m; ++i) {
      pos[i] = q[k][i - 1].first;
      sum[i] = sum[i - 1] + q[k][i - 1].second;
    }
    pos[m + 1] = n + 1;
    sum[m + 1] = -INF;
    top = 0;
    t[++top] = m + 1;
    for (int i = m; i >= 1; --i) {
      t[++top] = i;
      while (sum[t[top]] >= sum[i - 1]) top--;
      modify(1, 1, n, pos[i - 1] + 1, pos[i], pos[t[top]]);
    }
  }
  calc(1, 1, n, n + 1);
  printf("%lld", ans);
  return 0;
}

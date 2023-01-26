#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return x * s;
}
int C[1200005], mx;
void tadd(int i, int k) {
  for (; i <= mx + 1; i += i & -i) C[i] += k;
}
int tsum(int i) {
  int ans = 0;
  for (; i; i -= i & -i) ans += C[i];
  return ans;
}
int find_p(int pos) {
  int tmp = tsum(pos - 1);
  int l = 0, r = pos - 1, ans = r;
  while (l <= r) {
    if (tsum(((l + r) >> 1)) == tmp)
      ans = ((l + r) >> 1), r = ((l + r) >> 1) - 1;
    else
      l = ((l + r) >> 1) + 1;
  }
  return ans;
}
int find_s(int pos) {
  int tmp = tsum(pos);
  int l = pos + 1, r = mx + 1, ans = l;
  while (l <= r) {
    if (tsum(((l + r) >> 1)) == tmp)
      ans = ((l + r) >> 1), l = ((l + r) >> 1) + 1;
    else
      r = ((l + r) >> 1) - 1;
  }
  return ans;
}
struct Edge {
  int id, l, r;
  bool operator<(const Edge &a) const { return id < a.id; }
} edge[1200005];
struct EDGE {
  int to, nex;
} E[1200005 << 1];
int head[1200005];
void add(int i, int j) {
  static int t = 1;
  E[++t] = (EDGE){j, head[i]};
  head[i] = t;
}
int p[1200005], in[1200005], perf[1200005], dp[1200005], vis[1200005];
vector<int> vec_in[1200005], vec_out[1200005];
queue<int> que;
int main() {
  int n = read(), m = read(), cnt = 0;
  for (int i = 1; i <= m; i++) {
    edge[i].id = read(), edge[i].l = p[++cnt] = read(),
    edge[i].r = p[++cnt] = read();
  }
  sort(p + 1, p + 1 + cnt);
  int k = unique(p + 1, p + 1 + cnt) - p - 1;
  sort(edge + 1, edge + 1 + m);
  for (int i = 1; i <= m; i++) {
    edge[i].l = lower_bound(p + 1, p + 1 + k, edge[i].l) - p;
    edge[i].r = lower_bound(p + 1, p + 1 + k, edge[i].r) - p;
    vec_in[edge[i].l].push_back(edge[i].id);
    vec_out[edge[i].r].push_back(edge[i].id);
  }
  mx = n;
  for (int i = 1; i <= k; i++) {
    if (!vec_in[i].empty())
      for (int j = 0; j <= (int)vec_in[i].size() - 1; j++) {
        int tmp = vec_in[i][j];
        tadd(tmp, 1);
      }
    if (!vec_in[i].empty())
      for (int j = 0; j <= (int)vec_in[i].size() - 1; j++) {
        int tmp = vec_in[i][j], pre = find_p(tmp), suf = find_s(tmp);
        add(pre, tmp);
        add(tmp, suf);
        in[tmp]++;
        in[suf]++;
      }
    if (!vec_out[i].empty())
      for (int j = 0; j <= (int)vec_out[i].size() - 1; j++) {
        int tmp = vec_out[i][j];
        tadd(tmp, -1);
      }
    if (!vec_out[i].empty())
      for (int j = 0; j <= (int)vec_out[i].size() - 1; j++) {
        int tmp = vec_out[i][j], pre = find_p(tmp), suf = find_s(tmp);
        add(pre, suf);
        in[suf]++;
      }
  }
  que.push(0);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = head[now]; i; i = E[i].nex) {
      in[E[i].to]--;
      if (dp[E[i].to] < dp[now] + 1) {
        perf[E[i].to] = now;
        dp[E[i].to] = dp[now] + 1;
      }
      if (in[E[i].to] == 0) que.push(E[i].to);
    }
  }
  int tmp = n + 1, ans = -1;
  while (tmp) {
    tmp = perf[tmp];
    vis[tmp] = 1;
    ans++;
  }
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) printf("%d ", i);
  return 0;
}

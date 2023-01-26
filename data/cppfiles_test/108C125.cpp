#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int ans = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
int t, n;
struct node {
  int a, b;
  int id;
} p[100010];
int ans[100010];
int cmp(node a, node b) { return a.a > b.a; }
int cmp2(node a, node b) { return a.b > b.b; }
struct edge {
  int v, nxt;
} e[100010 * 2];
int head[100010], cnt = 0;
void ad(int u, int v) {
  e[++cnt].v = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
int bel[100010], sta[100010], dep[100010], low[100010], top, tot;
int in[100010], k;
bool vis[100010], inz[100010];
void tarjan(int st) {
  sta[++top] = st;
  vis[st] = true;
  inz[st] = true;
  dep[st] = low[st] = ++tot;
  for (int i = head[st]; i; i = e[i].nxt) {
    int to = e[i].v;
    if (!vis[to]) {
      tarjan(to);
      low[st] = min(low[st], low[to]);
    } else if (inz[to]) {
      low[st] = min(low[st], dep[to]);
    }
  }
  if (dep[st] == low[st]) {
    k++;
    int t;
    do {
      t = sta[top--];
      inz[t] = false;
      bel[t] = k;
    } while (t != st);
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    cnt = 0;
    k = 0;
    tot = 0;
    memset(vis, false, sizeof(vis));
    memset(inz, false, sizeof(inz));
    memset(in, 0, sizeof(in));
    memset(head, 0, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &p[i].a);
      p[i].id = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i < n; i++) ad(p[i].id, p[i + 1].id);
    sort(p + 1, p + 1 + n, cmp2);
    for (int i = 1; i < n; i++) ad(p[i].id, p[i + 1].id);
    for (int i = 1; i <= n; i++)
      if (!vis[i]) tarjan(i);
    for (int u = 1; u <= n; u++) {
      for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (bel[u] == bel[v]) continue;
        in[bel[v]]++;
      }
    }
    for (int i = 1; i <= n; i++)
      if (in[bel[i]] == 0)
        printf("1");
      else
        printf("0");
    printf("\n");
  }
  return 0;
}

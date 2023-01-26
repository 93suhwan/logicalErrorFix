#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
struct E {
  int to, cap, co, rev;
};
vector<E> e[40000];
void add_edge(int f, int t, int ca, int co) {
  e[f].push_back((E){t, ca, co, (int)e[t].size()});
  e[t].push_back((E){f, 0, -co, (int)e[f].size() - 1});
}
int h[40000], d[40000];
int prvv[40000], prve[40000];
long long mcf(int so, int si, int k) {
  long long res = 0;
  int f = k;
  while (f) {
    for (int i = 0; i <= si; i++) {
      d[i] = inf;
    }
    d[so] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, so));
    while (q.size()) {
      int v = q.top().second, c = -q.top().first;
      q.pop();
      if (d[v] != c) continue;
      for (int i = 0; i < e[v].size(); i++) {
        int w = e[v][i].to;
        if (!e[v][i].cap) continue;
        if (d[w] + h[w] > d[v] + h[v] + e[v][i].co) {
          d[w] = d[v] + h[v] + e[v][i].co - h[w];
          q.push(make_pair(-d[w], w));
          prvv[w] = v;
          prve[w] = i;
        }
      }
    }
    if (d[si] == inf) break;
    for (int i = 0; i <= si; i++) {
      h[i] += d[i];
    }
    int fl = inf;
    for (int i = si; i != so; i = prvv[i]) {
      fl = min(fl, e[prvv[i]][prve[i]].cap);
    }
    res += 1ll * fl * h[si];
    f -= fl;
    for (int i = si; i != so; i = prvv[i]) {
      e[prvv[i]][prve[i]].cap -= fl;
      e[i][e[prvv[i]][prve[i]].rev].cap += fl;
    }
  }
  return (k - f) * 2000000ll - res;
}
const int M = 1 << 20;
int b[M], a[M];
int id[M];
vector<int> vv[M];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int N = 1 << n;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    a[i] = 1000000 - a[i];
  }
  for (int i = 1; i < N; i++) {
    b[i] = b[i & (i - 1)] + 1;
  }
  vector<pair<int, int> > ps[2];
  for (int i = 0; i < N; i++) {
    ps[b[i] & 1].push_back(make_pair(-a[i], i));
  }
  for (int i = 0; i < 2; i++) {
    sort(ps[i].begin(), ps[i].end());
    if (ps[i].size() > k * 2) ps[i].resize(k * 2);
  }
  for (int l = 0; l < 2; l++) {
    for (int i = 0; i < ps[l].size(); i++) {
      int x = ps[l][i].second;
      for (int j = 0; j < n; j++) {
        int y = x ^ (1 << j);
        vv[x].push_back(y);
        vv[y].push_back(x);
      }
    }
  }
  vector<int> vs[2];
  for (int i = 0; i < N; i++) {
    if (vv[i].size()) vs[b[i] & 1].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    id[i] = -1;
  }
  int c = 0;
  int so = vs[0].size() + vs[1].size(), si = so + 1;
  for (int i = 0; i < vs[0].size(); i++) {
    int x = vs[0][i];
    add_edge(so, c, 1, a[x]);
    id[vs[0][i]] = c++;
  }
  for (int i = 0; i < vs[1].size(); i++) {
    int x = vs[1][i];
    add_edge(c, si, 1, a[x]);
    id[vs[1][i]] = c++;
  }
  for (int i = 0; i < vs[0].size(); i++) {
    int x = vs[0][i];
    for (int j = 0; j < n; j++) {
      int y = x ^ (1 << j);
      if (id[y] != -1) add_edge(i, id[y], 1, 0);
    }
  }
  printf("%lld\n", mcf(so, si, k));
  return 0;
}

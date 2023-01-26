#include <bits/stdc++.h>
using namespace std;
const int siz1 = 2e5, siz2 = 30, mod = 998244353;
const double eps = 1e-7;
struct edge {
  int v, w;
};
int t, n, m, root[siz1 * 2 + 5], enemy[siz1 * 2 + 5], subsz[siz1 * 2 + 5];
vector<edge> adj[siz1 + 5], ps[siz1 + 5];
void initdsu() {
  for (int i = 1; i <= n; ++i) {
    root[i] = i;
    root[i + n] = i + n;
    enemy[i] = i + n;
    enemy[i + n] = i;
    subsz[i] = subsz[i + n] = 1;
  }
}
int getroot(int i) {
  while (i != root[i]) {
    i = root[i] = root[root[i]];
  }
  return i;
}
int join(int u, int v) {
  int ru = getroot(u), rv = getroot(v);
  if (ru == rv) {
    return ru;
  }
  int nr = -1;
  if (subsz[ru] > subsz[rv]) {
    nr = ru;
    root[rv] = ru;
    subsz[ru] += subsz[rv];
  } else {
    nr = rv;
    root[ru] = rv;
    subsz[rv] += subsz[ru];
  }
  return nr;
}
bool merge(int u, int v, int p) {
  int ru = getroot(u), rv = getroot(v);
  int eu = getroot(enemy[ru]), ev = getroot(enemy[rv]);
  if ((!p && eu == rv) || (p && ru == rv)) {
    return false;
  }
  int n1 = -1, n2 = -1;
  if (!p) {
    n1 = join(ru, rv);
    n2 = join(eu, ev);
  } else {
    n1 = join(ru, ev);
    n2 = join(rv, eu);
  }
  enemy[n1] = n2;
  enemy[n2] = n1;
  return true;
}
int decide(int u, int v) {
  int ru = getroot(u), rv = getroot(v);
  int eu = getroot(enemy[ru]), ev = getroot(enemy[rv]);
  if (ru == rv) {
    merge(ru, rv, 0);
    return 0;
  } else if (eu == rv) {
    merge(eu, rv, 1);
    return 1;
  } else {
    merge(ru, rv, 0);
    return 0;
  }
}
int reduce(int v) {
  if (v == -1) {
    return v;
  }
  int p = 0;
  for (int i = 0; i < siz2; ++i) {
    p ^= (bool)(v & (1 << i));
  }
  return p;
}
void clear() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    ps[i].clear();
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    for (int i = 0; i < m; ++i) {
      int a, b, p;
      scanf("%d%d%d", &a, &b, &p);
      ps[a].push_back({b, p});
      ps[b].push_back({a, p});
    }
    initdsu();
    bool valid = true;
    for (int i = 1; i <= n; ++i) {
      for (const auto &e : adj[i]) {
        if (e.w == -1) {
          continue;
        }
        int wr = reduce(e.w);
        if (!merge(i, e.v, wr)) {
          valid = false;
          break;
        }
      }
      if (!valid) {
        break;
      }
      for (const auto &e : ps[i]) {
        if (!merge(i, e.v, e.w)) {
          valid = false;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }
    if (!valid) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int i = 1; i <= n; ++i) {
        for (const auto &e : adj[i]) {
          if (e.v < i) {
            continue;
          }
          if (e.w != -1) {
            printf("%d %d %d\n", i, e.v, e.w);
          } else {
            printf("%d %d %d\n", i, e.v, decide(i, e.v));
          }
        }
      }
    }
    clear();
  }
  return 0;
}

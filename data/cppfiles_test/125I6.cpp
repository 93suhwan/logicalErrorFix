#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], f1[605][605], f2[605][605], f3[605][605], ff1[605][605],
    ff2[605][605], base, ans, fa[605], w[605], val[605];
bool vis[605];
int fd(int k1) { return fa[k1] == k1 ? k1 : fa[k1] = fd(fa[k1]); }
vector<tuple<int, int, int> > e1[605];
bool used[605], pd[N];
void dfs1(int k1, int k2, int k3) {
  if (used[k1]) return;
  used[k1] = 1;
  for (auto& x : e1[k1])
    if (get<0>(x) != k2) {
      if (k3) ff1[k1][get<0>(x)] = k1;
      dfs1(get<0>(x), k1, k3 ^ 1);
    }
}
int main() {
  scanf("%d", &n);
  iota(fa, fa + 605, 0);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = (1); i <= (n - 1); ++i) {
    if (a[i] && a[i + 1] && a[i] == a[i + 1]) {
      vis[a[i]] = 1;
      ++base;
    }
  }
  for (int i = 1, j; i <= n; i = j) {
    j = i + 1;
    while (j <= n && (!!a[i]) == (!!a[j])) ++j;
    if (!a[i]) {
      if (i - 1 >= 1 && !vis[a[i - 1]] && j <= n && !vis[a[j]] &&
          a[i - 1] != a[j]) {
        int u = a[i - 1], v = a[j];
        if (u > v) swap(u, v);
        if ((j - i) & 1) {
          f1[u][v] += 1;
        } else {
          f2[u][v] += 1;
        }
      } else if ((j - i) & 1) {
        if (i - 1 >= 1 && !vis[a[i - 1]])
          vis[a[i - 1]] = 1, a[i] = a[i - 1];
        else if (j <= n && !vis[a[j]])
          vis[a[j]] = 1, a[j - 1] = a[j];
      }
    }
  }
  for (int i = (1); i <= (600); ++i)
    for (int j = (i + 1); j <= (600); ++j)
      if (f1[i][j] > 1) {
        f3[i][j] = 1;
        f1[i][j] = 0;
      }
  for (int i = 1, j; i <= n; i = j) {
    j = i + 1;
    while (j <= n && (!!a[i]) == (!!a[j])) ++j;
    if (!a[i]) {
      if (i - 1 >= 1 && !vis[a[i - 1]] && j <= n && !vis[a[j]] &&
          a[i - 1] != a[j]) {
        int u = a[i - 1], u_ = i, v = a[j], v_ = j - 1;
        if (u > v) swap(u, v);
        if ((j - i) & 1) {
          if (f3[u][v] == 1) {
            a[u_] = u;
            f3[u][v] += 1;
          } else if (f3[u][v] == 2) {
            a[v_] = v;
          }
        }
      }
    }
  }
  for (int i = (1); i <= (600); ++i)
    for (int j = (i + 1); j <= (600); ++j)
      if (f1[i][j] && f2[i][j]) f2[i][j] = 0;
  int ind = 0;
  for (int i = (1); i <= (600); ++i)
    for (int j = (i + 1); j <= (600); ++j)
      if (f1[i][j]) {
        if (fd(i) == fd(j)) {
          if (!w[fd(i)]) {
            e1[i].emplace_back(j, ++ind, 1);
            e1[j].emplace_back(i, ind, 1);
          }
        } else {
          if (!w[fd(i)] || !w[fd(j)]) {
            e1[i].emplace_back(j, ++ind, 1);
            e1[j].emplace_back(i, ind, 1);
            w[fd(i)] = w[fd(i)] || w[fd(j)];
            fa[fd(i)] = fd(j);
          }
        }
      }
  for (int i = (1); i <= (600); ++i)
    for (int j = (i + 1); j <= (600); ++j)
      if (f2[i][j]) {
        if (!w[fd(i)] && !w[fd(j)]) {
          w[fd(i)] = 1;
          fa[fd(i)] = fd(j);
          dfs1(i, 0, 0);
          dfs1(j, 0, 0);
          ff2[i][j] = 1;
          e1[i].emplace_back(j, ++ind, 2);
          e1[j].emplace_back(i, ind, 2);
        }
      }
  for (int i = (1); i <= (600); ++i)
    if (!used[i]) dfs1(i, 0, 1);
  for (int i = 1, j; i <= n; i = j) {
    j = i + 1;
    while (j <= n && (!!a[i]) == (!!a[j])) ++j;
    if (!a[i]) {
      if (i - 1 >= 1 && !vis[a[i - 1]] && j <= n && !vis[a[j]] &&
          a[i - 1] != a[j]) {
        int u = a[i - 1], u_ = i, v = a[j], v_ = j - 1;
        if (u > v) swap(u, v);
        if ((j - i) & 1) {
          if (ff1[u][v]) {
            if (ff1[u][v] == u) {
              a[u_] = u;
            } else {
              a[v_] = v;
            }
            ff1[u][v] = 0;
          }
        } else {
          if (ff2[v][u]) {
            if (ff2[u][v]) {
              a[u_] = u;
              a[v_] = v;
            }
            ff2[v][u] = 0;
          }
        }
      }
    }
  }
  for (int i = (1); i <= (n); ++i)
    if (a[i]) pd[a[i]] = 1;
  int cur = n;
  for (int i = 1; i + 1 <= n; i += 2) {
    if (!a[i] && !a[i + 1]) {
      while (cur >= 1 && pd[cur]) {
        --cur;
      }
      if (cur) {
        pd[cur] = 1;
        a[i] = a[i + 1] = cur;
      }
    }
  }
  for (int i = (1); i <= (n); ++i)
    if (!a[i]) a[i] = 1;
  for (int i = (1); i <= (n); ++i) printf("%d ", a[i]);
  return 0;
}

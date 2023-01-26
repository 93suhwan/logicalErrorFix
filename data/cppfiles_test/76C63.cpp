#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
map<pair<int, int>, bool> mark;
int vis[200009];
bool check(vector<int>& tmp) {
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      if (mark[{tmp[i], tmp[j]}]) return 0;
  return 1;
}
bool good(vector<int> tmp) {
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      if (!mark[{tmp[i], tmp[j]}]) return 0;
  return 1;
}
int T = 100;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    mark[{u, v}] = 1;
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dis(1, n);
  if (n <= T) {
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k <= n; k++)
          for (int h = k + 1; h <= n; h++)
            for (int l = h + 1; l <= n; l++)
              if (good(vector<int>{i, j, k, h, l})) {
                printf("%d %d %d %d %d\n", i, j, k, h, l);
                return 0;
              }
  }
  vector<int> v;
  while (1.0 * clock() / CLOCKS_PER_SEC < 0.98) {
    for (int i = 0, nd; i < 5; i++) {
      nd = dis(rng);
      while (vis[nd]) nd = dis(rng);
      v.push_back(nd);
      vis[nd] = 1;
    }
    if (check(v)) {
      for (int i = 0; i < 5; i++) printf("%d ", v[i]);
      puts("");
      return 0;
    }
    for (int i = 0; i < 5; i++) vis[v[i]] = 0;
    v.clear();
  }
  puts("-1");
  return 0;
}

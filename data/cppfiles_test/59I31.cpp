#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int a[1005], b[1005];
long long d[1005];
int from[1005];
int f[1005];
int vis[1005];
int Find(int first) {
  if (f[first] == first) return first;
  return f[first] = Find(f[first]);
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) v[i].clear();
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  vector<pair<int, int> > edge;
  for (int i = 0; i < m; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    edge.push_back(make_pair(first, second));
    v[first].push_back(second);
    v[second].push_back(first);
  }
  int Max = 1e9 + 1, Min = 0;
  while (Max > Min + 1) {
    int mid = (Max + Min) / 2;
    for (int i = 1; i <= n; i++) f[i] = i, d[i] = -1;
    while (true) {
      int now = mid;
      for (int i = 1; i <= n; i++) {
        d[i] = -1, vis[i] = 0;
        if (f[i] == 1) now += b[i];
      }
      queue<int> q;
      q.push(1);
      d[1] = now;
      vis[1] = 1;
      int ok = 0;
      vector<int> tmp;
      while (!q.empty()) {
        int first = q.front();
        q.pop();
        for (auto it : v[first]) {
          if (!vis[it]) {
            if (f[it] == 1) {
              q.push(it);
              vis[it] = 1;
              d[it] = d[1];
            } else {
              if (d[first] > a[it]) {
                q.push(it);
                vis[it] = 1;
                d[it] = d[first] + b[it];
                from[it] = first;
              }
            }
          } else {
            if (f[it] == 1) {
            } else {
              ok = 1;
              int a = first, b = it;
              while (f[a] != 1) tmp.push_back(a), a = from[a];
              while (f[b] != 1) tmp.push_back(b), b = from[b];
              break;
            }
          }
        }
        if (ok) break;
      }
      if (ok) {
        for (auto it : tmp) {
          f[it] = 1;
        }
      } else {
        break;
      }
    }
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (f[i] != 1) ok = 0;
    }
    if (ok)
      Max = mid;
    else
      Min = mid;
  }
  printf("%d\n", Max);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}

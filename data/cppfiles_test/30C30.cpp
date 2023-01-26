#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 10;
int n, q, a[N], p[N + N], lp[N];
int get(int v) {
  if (p[v] == v) return v;
  return p[v] = get(p[v]);
}
void unite(int u, int v) {
  u = get(u), v = get(v);
  if (u == v) return;
  if (rand() & 1) swap(u, v);
  p[u] = v;
}
bool was[N];
unordered_map<int, bool> used[N + N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < N + N; i++) p[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    was[a[i]] = 1;
  }
  for (int pr = 2; pr < N; pr++) {
    if (lp[pr]) continue;
    for (int i = pr; i < N; i += pr) {
      if (!lp[i]) lp[i] = pr;
      if (was[i]) {
        unite(i, N + pr);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<int> v;
    int x = a[i];
    while (x > 1) {
      int p = lp[x];
      v.push_back(N + p);
      while (x % p == 0) x /= p;
    }
    x = a[i] + 1;
    while (x > 1) {
      int p = lp[x];
      v.push_back(N + p);
      while (x % p == 0) x /= p;
    }
    for (auto x : v)
      for (auto y : v) {
        used[get(x)][get(y)] = used[get(y)][get(x)] = 1;
      }
  }
  while (q--) {
    int s, t;
    scanf("%d%d", &s, &t);
    if (get(a[s]) == get(a[t])) {
      puts("0");
      continue;
    }
    vector<int> v1, v2;
    int x = a[s];
    while (x > 1) {
      int p = lp[x];
      v1.push_back(N + p);
      while (x % p == 0) x /= p;
    }
    x = a[t];
    while (x > 1) {
      int p = lp[x];
      v2.push_back(N + p);
      while (x % p == 0) x /= p;
    }
    bool found = 0;
    for (auto x : v1) {
      for (auto y : v2) {
        if (used[get(x)][get(y)]) {
          found = 1;
          break;
        }
      }
    }
    if (found)
      puts("1");
    else
      puts("2");
  }
}

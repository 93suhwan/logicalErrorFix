#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long t[10000000], tmin[10000000];
void push(int l, int r, int v) {
  if (t[v] != -2) {
    tmin[v] += t[v];
    if (l != r) {
      t[v * 2 + 1] = t[v];
      t[v * 2 + 2] = t[v];
      tmin[v * 2 + 1] = max(tmin[v * 2 + 1], tmin[v]);
      tmin[v * 2 + 2] = max(tmin[v * 2 + 2], tmin[v]);
    }
    t[v] = -2;
  }
}
void add(int l, int r, int lx, int rx, int zn, int v) {
  if (l > rx || r < lx) return;
  push(l, r, v);
  if (l >= lx && r <= rx) {
    t[v] = zn;
    push(l, r, v);
    return;
  }
  add(l, (l + r) / 2, lx, rx, zn, v * 2 + 1);
  add((l + r) / 2 + 1, r, lx, rx, zn, v * 2 + 2);
  tmin[v] = min(tmin[v * 2 + 1], tmin[v * 2 + 2]);
}
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<long long, pair<long long, long long> > > a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].second.first >> a[i].second.second >> a[i].first;
  sort(a.begin(), a.end());
  for (int i = 0; i < 10000000; i++) {
    t[i] = -2;
    tmin[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].second.first == 1) a[i].second.first--;
    a[i].second.first++;
  }
  int l = -1;
  long long res = 1e18;
  for (int i = 0; i < n; i++) {
    while (tmin[0] == 0) {
      if (l == n) break;
      l++;
      if (l < n)
        add(1, m, a[l].second.first, a[l].second.second, 1, 0);
      else
        break;
    }
    if (tmin[0] > 0) res = min(res, a[l].first - a[i].first);
    add(1, m, a[i].second.first, a[i].second.second, -1, 0);
  }
  cout << res << "\n";
}

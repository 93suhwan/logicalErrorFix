#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long t[10000000], tsum[10000000];
void push(int l, int r, int v) {
  if (t[v] != -1)
    tsum[v] = t[v] * (r - l + 1);
  else if (l != r)
    tsum[v] = tsum[v * 2 + 1] + tsum[v * 2 + 2];
  if (t[v] != -1 && l != r) {
    t[v * 2 + 1] = t[v];
    t[v * 2 + 2] = t[v];
    tsum[v * 2 + 1] = t[v] * ((l + r) / 2 - l + 1);
    tsum[v * 2 + 2] = t[v] * (r - (l + r) / 2);
    t[v] = -1;
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
  push(l, r, v);
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
    t[i] = -1;
    tsum[i] = 0;
  }
  int l = -1;
  long long res = 1e18;
  for (int i = 0; i < n; i++) {
    while (tsum[0] != m) {
      l++;
      if (l < n)
        add(0, m, a[l].second.first, a[l].second.second, 1, 0);
      else
        break;
    }
    if (tsum[0] >= m) res = min(res, a[l].first - a[i].first);
    add(0, m, a[i].second.first, a[i].second.second, 0, 0);
  }
  cout << res << "\n";
}

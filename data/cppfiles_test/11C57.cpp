#include <bits/stdc++.h>
using namespace std;
int n;
int a[200007];
int c[1000007];
vector<pair<int, int> > p;
void add(int v, int val) {
  v += 200000;
  for (int i = v; i <= 400007; i += ((i) & (-i))) {
    c[i] = max(c[i], val);
  }
  return;
}
int ask(int v) {
  v += 200000;
  int res = 0;
  for (int i = v; i; i -= ((i) & (-i))) {
    res = max(res, c[i]);
  }
  return res;
}
vector<int> te[200007];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > n || a[i] > i) continue;
    p.emplace_back(a[i], i - a[i]);
  }
  int ans = 0;
  sort(p.begin(), p.end());
  for (auto [x, y] : p) {
    te[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > q;
    for (auto y : te[i]) {
      int tp = ask(y) + 1;
      ans = max(ans, tp);
      q.emplace_back(y, tp);
    }
    for (auto [y, tp] : q) {
      add(y, tp);
    }
  }
  printf("%d\n", ans);
  return 0;
}

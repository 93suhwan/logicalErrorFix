#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 11;
int ans;
vector<vector<int> > bad;
vector<int> cand, best;
vector<int> a[N];
void init() {}
int pw(int x, int n) {
  int res = 1;
  for (int i = 0; i < n; ++i) {
    res *= min(x, ((int)(a[i]).size()));
  }
  return res;
}
void gen(int pos, int n, int x) {
  if (pos >= n) {
    auto it = lower_bound((bad).begin(), (bad).end(), cand);
    if (it != bad.end() && *it == cand) {
      return;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += a[i][cand[i]];
    }
    if (res > ans) {
      ans = res;
      best = cand;
    }
    return;
  }
  for (int i = max(((int)(a[pos]).size()) - x, 0); i < ((int)(a[pos]).size());
       ++i) {
    cand.push_back(i);
    gen(pos + 1, n, x);
    cand.pop_back();
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int sz;
    scanf("%d", &sz);
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  bad.clear();
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    vector<int> cur(n);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &cur[j]);
      --cur[j];
    }
    bad.push_back(std::move(cur));
  }
  sort((bad).begin(), (bad).end());
  int x = 1, maxx = 0;
  for (int i = 0; i < n; ++i) {
    maxx = max(maxx, ((int)(a[i]).size()));
  }
  while (x < maxx && pw(x, n) <= 10 * m) {
    ++x;
  }
  ans = -1;
  gen(0, n, x);
  for (int y : best) {
    printf("%d ", y + 1);
  }
  puts("");
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}

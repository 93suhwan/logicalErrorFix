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
void gen(int pos, int prod, int n, int m) {
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
  for (int i = ((int)(a[pos]).size()) - 1; i >= 0; --i) {
    if (((int)(a[pos]).size()) - i >= 100 * m / prod) {
      break;
    }
    cand.push_back(i);
    gen(pos + 1, prod * (((int)(a[pos]).size()) - i), n, m);
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
  ans = -1;
  gen(0, 1, n, m);
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2020;
const int inf = 1e9;
int y[N];
ll res[N], res2[N];
char a[N][N];
int up[N][N], down[N][N];
vector<pair<int, int> > st;
void init() {}
ll sqr(int x) { return ll(x) * x; }
ll vec(int x1, int y1, int x2, int y2) { return ll(x1) * y2 - ll(x2) * y1; }
bool bad(const pair<int, int>& a, const pair<int, int>& b,
         const pair<int, int>& c) {
  return vec(b.first - a.first, b.second - a.second, c.first - b.first,
             c.second - b.second) <= 0;
}
ll calc(const pair<int, int>& p, int x) {
  return sqr(x) - ll(2) * x * p.first + p.second;
}
void calc(int m, ll* res) {
  st.clear();
  int ptr = 0;
  for (int i = 0; i <= m; ++i) {
    res[i] = y[i];
    if (((int)(st).size()) > 0) {
      while (ptr + 1 < ((int)(st).size()) &&
             calc(st[ptr + 1], i) <= calc(st[ptr], i)) {
        ++ptr;
      }
      res[i] = min(res[i], calc(st[ptr], i));
    }
    while (((int)(st).size()) >= 2 && bad(st[((int)(st).size()) - 2], st.back(),
                                          make_pair(i, y[i] + sqr(i)))) {
      st.pop_back();
      ptr = min(ptr, ((int)(st).size()) - 1);
    }
    st.push_back(make_pair(i, y[i] + sqr(i)));
  }
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (a[i][j] == '1') {
        up[i][j] = i;
      } else if (i > 0) {
        up[i][j] = up[i - 1][j];
      } else {
        up[i][j] = -1;
      }
    }
  }
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= m; ++j) {
      if (a[i][j] == '1') {
        down[i][j] = i;
      } else if (i + 1 <= n) {
        down[i][j] = down[i + 1][j];
      } else {
        down[i][j] = -1;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      y[j] = inf;
      if (up[i][j] != -1) {
        y[j] = min(ll(y[j]), sqr(i - up[i][j]));
      }
      if (down[i][j] != -1) {
        y[j] = min(ll(y[j]), sqr(i - down[i][j]));
      }
    }
    calc(m, res);
    reverse(y, y + m + 1);
    calc(m, res2);
    reverse(res2, res2 + m + 1);
    for (int j = 0; j <= m; ++j) {
      ans += min(res[j], res2[j]);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > P[3];
void compress(vector<int> &V) {
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
}
int C[3][100005];
int solve() {
  memset(C, 0, sizeof(C));
  for (int i = 0; i < 3; ++i) sort(P[i].begin(), P[i].end());
  int i0 = 0, i1 = 0, i2 = 0;
  int y = 0, up = 0, dn = 0;
  int ret = 0;
  for (int x = 1; x <= n; ++x) {
    while (i0 < n / 3 && P[0][i0].first < x) ++i0;
    while (i1 < n / 3 && P[1][i1].first <= x) {
      int py = P[1][i1++].second;
      if (py >= y) ++up;
    }
    while (i2 < n / 3 && P[2][i2].first <= x) {
      int py = P[2][i2++].second;
      if (py <= y) ++dn;
    }
    ret = max(ret, min({up, dn, n / 3 - i0}));
    while (up < dn) {
      up += C[1][y - 1];
      dn -= C[2][y];
      --y;
      ret = max(ret, min({up, dn, n / 3 - i0}));
    }
    while (up > dn) {
      up -= C[1][y];
      dn += C[2][y + 1];
      ++y;
      ret = max(ret, min({up, dn, n / 3 - i0}));
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(30);
  cout << fixed;
  cin >> n;
  vector<int> X, Y;
  for (int i = 1; i <= n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    P[c - 1].emplace_back(x, y);
    X.push_back(x);
    Y.push_back(y);
  }
  compress(X);
  compress(Y);
  for (int i = 0; i < 3; ++i) {
    for (auto &[x, y] : P[i]) {
      x = upper_bound(X.begin(), X.end(), x) - X.begin();
      y = upper_bound(Y.begin(), Y.end(), y) - Y.begin();
    }
  }
  int ans = 0;
  for (int xy = 0; xy < 2; ++xy) {
    for (int f = 0; f < 2; ++f) {
      ans = max(ans, solve());
      swap(P[0], P[1]);
      ans = max(ans, solve());
      swap(P[0], P[2]);
      ans = max(ans, solve());
      swap(P[1], P[2]);
      ans = max(ans, solve());
      swap(P[0], P[1]);
      ans = max(ans, solve());
      swap(P[0], P[2]);
      ans = max(ans, solve());
      swap(P[1], P[2]);
      for (int i = 0; i < 3; ++i) {
        for (auto &[x, y] : P[i]) x = n + 1 - x;
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (auto &[x, y] : P[i]) swap(x, y);
    }
  }
  printf("%d\n", ans * 3);
  return 0;
}

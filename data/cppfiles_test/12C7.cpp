#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
const int md = 1e9 + 7;
const int INFi = 2e9;
struct ConvexHull {
  struct Line {
    int k, b;
    int get(int x) { return k * x + b; }
  };
  int intersect(Line &a, Line &b) {
    assert(a.k != b.k);
    if (a.b - b.b >= 0) return (a.b - b.b + (b.k - a.k - 1)) / (b.k - a.k);
    return (a.b - b.b) / (b.k - a.k);
  }
  vector<Line> lines;
  vector<int> xx;
  int uk = 0;
  void add(int k, int b) {
    Line a = {k, b};
    while (!lines.empty() && intersect(a, lines.back()) <= xx.back()) {
      xx.pop_back();
      lines.pop_back();
    }
    if (!lines.empty()) {
      xx.push_back(intersect(a, lines.back()));
    } else {
      xx.push_back(-INFi);
    }
    lines.push_back(a);
  }
  int get(int x) {
    while (uk + 1 < (int)xx.size() && xx[uk + 1] <= x) uk++;
    return lines[uk].get(x);
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  n++;
  m++;
  vvi a(n, vi(m));
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      char x;
      cin >> x;
      a[i][j] = x - '0';
    }
  vvi near(n, vi(m, INFi));
  for (int j = 0; j < (m); ++j) {
    int last = -1;
    for (int i = 0; i < (n); ++i) {
      if (a[i][j]) last = i;
      if (last != -1) near[i][j] = min(near[i][j], i - last);
    }
    last = n;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i][j]) last = i;
      if (last != n) near[i][j] = min(near[i][j], last - i);
    }
  }
  ll ans = 0;
  for (int i = 0; i < (n); ++i) {
    ConvexHull cht;
    for (int j = 0; j < (m); ++j) {
      if (near[i][j] == INFi) continue;
      int k = -2 * j;
      int b = near[i][j] * near[i][j] + j * j;
      cht.add(k, b);
    }
    for (int j = 0; j < (m); ++j) {
      ans += cht.get(j) + 1ll * j * j;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}

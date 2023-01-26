#include <bits/stdc++.h>
using namespace std;
int const N = 1e3 + 5;
class dsu {
 public:
  int _n;
  std::vector<int> p;
  dsu() : _n(0){};
  explicit dsu(int n) : _n(n), p(n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    p[x] += p[y];
    p[y] = x;
    return x;
  }
  void init(int n) {
    p.resize(n);
    for (int i = 1; i < n; i++) p[i] = i;
  }
  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  int leader(int a) {
    assert(0 <= a && a < _n);
    if (p[a] < 0) return a;
    return (p[a] == a) ? a : p[a] = leader(p[a]);
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -p[leader(a)];
  }
  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);
    for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }
};
int g[N][N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<dsu> v(m + 2, dsu(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> g[i][j];
  }
  for (int i = 1; i <= m; i++) {
    v[i].init(n + 1);
    for (int j = 1; j <= n; j++) {
      if (g[j][i] == 2) v[i].p[j] = j + 1;
    }
  }
  while (k--) {
    int j;
    cin >> j;
    int i = v[j].leader(1);
    while (i <= n) {
      v[j].p[i] = i + 1;
      if (g[i][j] == 1)
        g[i][j++] = 2;
      else
        g[i][j--] = 2;
      i = v[j].leader(i);
      ;
    }
    cout << j << " ";
  }
}

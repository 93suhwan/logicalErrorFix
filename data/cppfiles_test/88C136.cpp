#include <bits/stdc++.h>
using namespace std;
template <int N>
class BIT {
 private:
  int n, bit[N];

 public:
  void init(int _n) {
    n = _n;
    fill(bit, bit + n + 1, 0);
  }
  void add(int i, int v) {
    for (; i <= n; i += i & -i) bit[i] += v;
  }
  int get(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
  }
};
const int N = 300 + 1;
const int INF = 1e8;
int n, m;
int sight[N * N];
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++) cin >> sight[i];
}
inline int row_id(int x) { return (x - 1) / m + 1; }
inline int col_id(int x) { return (x - 1) % m + 1; }
int val[N * N + 1], seat[N * N], ranking[N * N];
BIT<N> bit[N];
void solve() {
  iota(ranking + 1, ranking + n * m + 1, 1);
  sort(ranking + 1, ranking + n * m + 1, [=](int i, int j) {
    if (sight[i] != sight[j]) return sight[i] < sight[j];
    return i > j;
  });
  for (int i = 1; i <= n * m;) {
    int j = i;
    while (j + 1 <= n * m and sight[ranking[j + 1]] == sight[ranking[i]]) j++;
    vector<int> p, r;
    for (int k = i; k <= j; k++) {
      p.push_back(ranking[k]);
      r.push_back(k);
    }
    sort(p.begin(), p.end());
    sort(r.begin(), r.end(), [=](int i, int j) {
      if (row_id(i) != row_id(j)) return row_id(i) < row_id(j);
      return col_id(i) > col_id(j);
    });
    for (int ptr = 0, k = i; k <= j; k++, ptr++) ranking[r[ptr]] = p[ptr];
    i = j + 1;
  }
  for (int i = 1; i <= n * m; i++) seat[ranking[i]] = i;
  for (int i = 1; i <= n; i++) bit[i].init(m);
  int ans = 0;
  for (int p = 1; p <= n * m; p++) {
    int i = row_id(seat[p]);
    int j = col_id(seat[p]);
    ans += bit[i].get(j);
    bit[i].add(j, +1);
  }
  cout << ans << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    input();
    solve();
  }
  return 0;
}

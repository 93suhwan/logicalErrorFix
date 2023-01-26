#include <bits/stdc++.h>
using namespace std;
void abc() { cout << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cout << a << ' ', abc(b...);
}
template <typename T>
void printv(T l, T r) {
  for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
template <typename T>
ostream& operator<<(ostream& o, vector<T> a) {
  bool is = false;
  if (a.empty()) return o << "{}";
  for (T i : a) {
    o << (is ? ' ' : '{'), is = true, o << i;
  }
  return o << '}';
}
template <typename T>
struct vv : vector<vector<T>> {
  vv(int n, int m, T v) : vector<vector<T>>(n, vector<T>(m, v)) {}
  vv() {}
};
template <typename T>
struct vvv : vector<vv<T>> {
  vvv(int n, int m, int k, T v) : vector<vv<T>>(n, vv<T>(m, k, v)) {}
  vvv() {}
};
const int mod = 998244353, N = 1000001, logN = 20, K = 48763, KK = 331983854;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long int> pw(N, 1);
  for (int i = 1; i < N; ++i) pw[i] = pw[i - 1] * 2 % mod;
  map<pair<int, int>, int> cur;
  vector<int> wrong(2, 0);
  vv<int> wrong_row(n, 2, 0), wrong_col(m, 2, 0);
  vector<int> cnt_row(4, 0), cnt_col(4, 0);
  cnt_row[3] = n, cnt_col[3] = m;
  auto move = [&](int x, int y, int v, int chg) {
    cnt_row[!wrong_row[x][0] << 1 | !wrong_row[x][1]]--;
    cnt_col[!wrong_col[y][0] << 1 | !wrong_col[y][1]]--;
    if ((x + y) % 2 == v)
      wrong[1] += chg;
    else
      wrong[0] += chg;
    if (y % 2 == v)
      wrong_row[x][1] += chg;
    else
      wrong_row[x][0] += chg;
    if (x % 2 == v)
      wrong_col[y][1] += chg;
    else
      wrong_col[y][0] += chg;
    cnt_row[!wrong_row[x][0] << 1 | !wrong_row[x][1]]++;
    cnt_col[!wrong_col[y][0] << 1 | !wrong_col[y][1]]++;
  };
  while (q--) {
    int x, y, v;
    cin >> x >> y >> v, --x, --y;
    if (cur.count({x, y})) {
      int t = cur[{x, y}];
      cur.erase({x, y});
      move(x, y, t, -1);
    }
    if (v != -1) {
      cur[{x, y}] = v;
      move(x, y, v, 1);
    }
    long long int ans = 0;
    if (!cnt_row[0]) ans += pw[cnt_row[3]];
    if (!cnt_col[0]) ans += pw[cnt_col[3]];
    if (!wrong[0]) ans--;
    if (!wrong[1]) ans--;
    cout << ans % mod << endl;
  }
}

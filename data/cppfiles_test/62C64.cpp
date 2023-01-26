#include <bits/stdc++.h>
using namespace std;
template <class T>
void _W(const T &x) {
  cout << x;
}
template <class T>
void _W(T &x) {
  cout << x;
}
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++)) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << ", ";
  W(tail...);
}
const int N = 1e3 + 10;
const long long mod = 998244353;
long long n, m;
void solve() {
  int q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m, 1));
  long long ans = 0;
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {
      if (x == 0) {
        for (int k = 1;; k++) {
          int nx = x + k / 2;
          int ny = y + (k + 1) / 2;
          if (nx == n || ny == m) break;
          ans += k;
        }
      }
      if (y == 0) {
        for (int k = 1;; k++) {
          int nx = x + (k + 1) / 2;
          int ny = y + k / 2;
          if (nx == n || ny == m) break;
          ans += k;
        }
      }
    }
  ans += n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    for (int i = 0; i < 2; i++) {
      int l = 1, r = 1;
      while (1) {
        int nx = x + (l + i) / 2;
        int ny = y + (l + !i) / 2;
        if (nx == n || ny == m || a[nx][ny] == 0) break;
        ++l;
      }
      while (1) {
        int nx = x - (r + !i) / 2;
        int ny = y - (r + i) / 2;
        if (nx < 0 || ny < 0 || a[nx][ny] == 0) break;
        ++r;
      }
      if (a[x][y] == 0) {
        ans += l * r;
      } else {
        ans -= l * r;
      }
    }
    ans += a[x][y];
    a[x][y] ^= 1;
    ans -= a[x][y];
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}

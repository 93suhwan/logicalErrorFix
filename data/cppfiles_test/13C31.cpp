#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T, typename U>
T mymax(T &a, U b) {
  if (a < b) a = b;
  return a;
}
template <typename T, typename U>
T mymin(T &a, U b) {
  if (a > b) a = b;
  return a;
}
const int MXN = 2 * 1e5 + 5;
typedef complex<long long> P;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> a(n, vector<char>(m));
  bool ok = 1;
  if (n % 2 == 1) {
    int each_row = m / 2;
    if (k % each_row == 0 && (k / each_row) & 1) ok = 0;
    int od = k / each_row;
    if (od % 2 == 0 && od > 0) od--;
    int left = k - each_row * od;
    if (od & 1 && left % 2 == 0 && left > 0) ok = 0;
    if (!ok) {
      cout << "YES\n";
      int c = 0;
      for (int i = 0; i < od; i++) {
        if (i % 2 == 0)
          c = 0;
        else
          c = 1;
        for (int j = 0; j < m; j += 2) {
          a[i][j] = 'i' + c;
          a[i][j + 1] = 'i' + c;
          c++;
          c %= 2;
        }
      }
      for (int i = od; i < (n / 2) * 2; i += 2) {
        int c = 0;
        for (int j = 0; j < m; j += 2) {
          if (left == 0) goto end;
          a[i][j] = 'a' + c;
          a[i][j + 1] = 'a' + c;
          c++;
          c %= 2;
          a[i + 1][j] = 'a' + c;
          a[i + 1][j + 1] = 'a' + c;
          left -= 2;
        }
      }
    end:
      c = 0;
      for (int j = 0; j < m; j++) {
        char ch = 'x';
        if (j % 2 == 1)
          ch = 'u';
        else
          ch = 'x';
        for (int i = od; i < (n / 2) * 2; i += 2) {
          if (!a[i][j]) {
            a[i][j] = ch + c;
            a[i + 1][j] = ch + c;
            c++;
            c %= 2;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];
        cout << endl;
      }
    } else
      cout << "NO\n";
  } else if (k % 2 == 0 && k <= (m / 2) * n) {
    cout << "YES\n";
    for (int i = 0; i < n; i += 2) {
      int c = 0;
      for (int j = 0; j < (m / 2) * 2; j += 2) {
        if (k == 0) goto end1;
        a[i][j] = 'a' + c;
        a[i][j + 1] = 'a' + c;
        c++;
        c %= 2;
        a[i + 1][j] = 'a' + c;
        a[i + 1][j + 1] = 'a' + c;
        k -= 2;
      }
    }
  end1:
    int c = 0;
    for (int j = 0; j < m; j++) {
      char ch = 'x';
      if (j % 2 == 1)
        ch = 'u';
      else
        ch = 'x';
      for (int i = 0; i < n; i += 2) {
        if (!a[i][j]) {
          a[i][j] = ch + c;
          a[i + 1][j] = ch + c;
          c++;
          c %= 2;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j];
      cout << endl;
    }
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}

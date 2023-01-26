#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string to_string(char x) { return (string) "\'" + x + "\'"; }
string to_string(const string &x) { return '\"' + x + '\"'; }
string to_string(const char *x) { return to_string((string)x); }
string to_string(bool x) { return x ? "true" : "false"; }
template <typename T, typename V>
string to_string(const pair<T, V> &x) {
  return '(' + to_string(x.first) + ',' + to_string(x.second) + ')';
}
template <typename T>
string to_string(const T &x) {
  int f = 0;
  string r;
  for (auto &i : x) r += (f++ ? "," : "") + to_string(i);
  return '{' + r + '}';
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  cerr << to_string(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int N = 1008;
int a[N][8];
int n;
void calc() {
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= 5; j++) {
      int x = 0, y = 0, z = 0;
      for (int k = 1; k <= n; k++) {
        if (a[k][i] == 1 && a[k][j] == 0) {
          x += 1;
        }
        if (a[k][i] == 0 && a[k][j] == 1) {
          y += 1;
        }
        if (a[k][i] == 1 && a[k][j] == 1) {
          z += 1;
        }
        if (x > y) {
          swap(x, y);
        }
      }
      if (x + y + z == n && x + z >= n / 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        cin >> a[i][j];
      }
    }
    calc();
  }
}

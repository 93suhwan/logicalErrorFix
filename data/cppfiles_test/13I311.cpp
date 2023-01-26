#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void dout(string name, int idx, T arg) {
  cerr << name << " = " << to_string(arg);
}
template <typename T1, typename... T2>
void dout(string names, int idx, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " = " << to_string(arg) << ", ";
  dout(names.substr(names.find(',') + 2), idx + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int qq = 0;
  while (tt--) {
    ++qq;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, -1));
    bool ok = true;
    int z = 0;
    if (n % 2 == 1) {
      for (int i = 0; i < m / 2; i++) {
        if (k == 0) {
          ok = false;
          break;
        }
        a[n - 1][2 * i] = (n - 1 + i) % 2;
        a[n - 1][2 * i + 1] = (n - 1 + i) % 2;
        --k;
      }
    }
    if (k % 2) {
      ok = false;
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    for (int j = 0; j < m / 2; j++) {
      if (k == 0) {
        break;
      }
      for (int i = 0; i < n; i++) {
        a[i][2 * j] = (i + j) % 2;
        a[i][2 * j + 1] = (i + j) % 2;
        --k;
        if (k == 0) {
          break;
        }
      }
    }
    if (k > 0) {
      ok = false;
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < m; j++) {
        if (a[2 * i][j] == -1) {
          a[2 * i][j] = (i + j) % 2 + 2;
          a[2 * i + 1][j] = (i + j) % 2 + 2;
        } else if (a[2 * i + 1][j] == -1) {
          a[2 * i + 1][j] = (i + j) % 2 + 2;
          a[2 * i + 2][j] = (i + j) % 2 + 2;
        }
      }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == -1) {
          42;
        }
        assert(a[i][j] > -1);
        cout << (char)(a[i][j] + 'a');
      }
      cout << '\n';
    }
  }
  return 0;
}

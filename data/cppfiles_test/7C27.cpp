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
template <typename T>
struct vvvv : vector<vvv<T>> {
  vvvv(int n, int m, int k, int t, T v)
      : vector<vvv<T>>(n, vvv<T>(m, k, t, v)) {}
  vvvv() {}
};
const int mod = 998244353, N = 1000001, logN = 20, K = 111;
vector<int> build_fail(string& s) {
  vector<int> f(s.length() + 1, 0);
  int k = 0;
  for (int i = 1; i < s.length(); ++i) {
    while (k && s[k] != s[i]) k = f[k];
    if (s[k] == s[i]) k++;
    f[i + 1] = k;
  }
  return f;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  s = "$" + s;
  vector<int> f = build_fail(t);
  vvv<int> dp(n + 1, m, n + 1, 1 << 30);
  dp[0][0][0] = 0;
  vv<int> pt(m, 2, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= 1; ++j) {
      int k = i;
      while (k && '0' + j != t[k]) k = f[k];
      if ('0' + j == t[k]) k++;
      pt[i][j] = k;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        int nj = pt[j][s[i] - '0'], nk = k;
        if (nj == m) nk++, nj = f[nj];
        dp[i][nj][nk] = min(dp[i][nj][nk], dp[i - 1][j][k]);
        nj = pt[j][(s[i] - '0') ^ 1], nk = k;
        if (nj == m) nk++, nj = f[nj];
        dp[i][nj][nk] = min(dp[i][nj][nk], dp[i - 1][j][k] + 1);
      }
    }
  }
  for (int i = 0; i <= n - m + 1; ++i) {
    int ans = 1 << 30;
    for (int j = 0; j < m; ++j) {
      ans = min(ans, dp[n][j][i]);
    }
    if (ans == 1 << 30) ans = -1;
    cout << ans << ' ';
  }
  cout << endl;
}

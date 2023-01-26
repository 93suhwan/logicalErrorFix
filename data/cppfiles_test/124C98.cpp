#include <bits/stdc++.h>
using namespace std;
void abc() { cout << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cout << a << ' ', abc(b...);
}
template <typename T>
void printv(T l, T r) {
  while (l != r) cout << *l << " \n"[++l == r];
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
  if (a.empty()) return o << "{}";
  bool is = false;
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
const int mod = 1e9 + 7, N = 200010, logN = 17, M = N * 40;
bool ok0(char c) { return c == '0' || c == '?'; }
bool ok1(char c) { return c == '1' || c == '?'; }
void add(int& i, long long int j) {
  j %= mod;
  i += j;
  if (i >= mod) i -= mod;
  if (i < 0) i += mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vv<int> dp(n * 2 + 1, n + 1, 0), cnt(n * 2 + 1, n + 1, 0);
    dp[n][0] = 0, cnt[n][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 2 * n; ++j) {
        if (ok1(s[0][i]) && ok1(s[1][i])) {
          add(dp[j][i + 1], dp[j][i]);
          add(cnt[j][i + 1], cnt[j][i]);
        }
        if (ok0(s[0][i]) && ok0(s[1][i])) {
          add(dp[j][i + 1], dp[j][i]);
          add(cnt[j][i + 1], cnt[j][i]);
        }
        if (ok1(s[0][i]) && ok0(s[1][i])) {
          if (i & 1) {
            if (j <= n && j) {
              add(dp[j - 1][i + 1], dp[j][i] - 1ll * i * cnt[j][i]);
              add(cnt[j - 1][i + 1], cnt[j][i]);
            } else if (j) {
              add(dp[j - 1][i + 1], dp[j][i] + 1ll * i * cnt[j][i]);
              add(cnt[j - 1][i + 1], cnt[j][i]);
            }
          } else {
            if (j >= n && j + 1 <= 2 * n) {
              add(dp[j + 1][i + 1], dp[j][i] - 1ll * i * cnt[j][i]);
              add(cnt[j + 1][i + 1], cnt[j][i]);
            } else if (j + 1 <= 2 * n) {
              add(dp[j + 1][i + 1], dp[j][i] + 1ll * i * cnt[j][i]);
              add(cnt[j + 1][i + 1], cnt[j][i]);
            }
          }
        }
        if (ok0(s[0][i]) && ok1(s[1][i])) {
          if (i & 1 ^ 1) {
            if (j <= n && j) {
              add(dp[j - 1][i + 1], dp[j][i] - 1ll * i * cnt[j][i]);
              add(cnt[j - 1][i + 1], cnt[j][i]);
            } else if (j) {
              add(dp[j - 1][i + 1], dp[j][i] + 1ll * i * cnt[j][i]);
              add(cnt[j - 1][i + 1], cnt[j][i]);
            }
          } else {
            if (j >= n && j + 1 <= 2 * n) {
              add(dp[j + 1][i + 1], dp[j][i] - 1ll * i * cnt[j][i]);
              add(cnt[j + 1][i + 1], cnt[j][i]);
            } else if (j + 1 <= 2 * n) {
              add(dp[j + 1][i + 1], dp[j][i] + 1ll * i * cnt[j][i]);
              add(cnt[j + 1][i + 1], cnt[j][i]);
            }
          }
        }
      }
    }
    cout << dp[n][n] << endl;
  }
}

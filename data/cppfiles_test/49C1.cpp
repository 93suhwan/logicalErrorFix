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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 80000;
long long int modpow(long long int a, int b) {
  long long int ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vv<int> inv(n, n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      inv[i][j] = modpow((a[i] + a[j]) % mod, mod - 2);
    }
  vector<long long int> dp(1 << n, 1);
  for (int s = 0; s < 1 << n; ++s) {
    vector<int> v;
    for (int i = 0; i < n; ++i)
      if (s >> i & 1) v.push_back(i);
    for (int t = s ^ (s & (-s)); t > 0; t = (t - 1) & s) {
      long long int res = 1;
      for (int i : v)
        if (t >> i & 1) {
          for (int j : v)
            if (~t >> j & 1) {
              res = res * a[j] % mod * inv[i][j] % mod;
            }
        }
      dp[s] -= dp[t] * res % mod;
      if (dp[s] < 0) dp[s] += mod;
    }
  }
  long long int ans = 0;
  for (int s = 0; s < 1 << n; ++s) {
    int k = __builtin_popcount(s);
    long long int res = dp[s];
    for (int i = 0; i < n; ++i)
      if (s >> i & 1) {
        for (int j = 0; j < n; ++j)
          if (~s >> j & 1) {
            res = res * a[i] % mod * inv[i][j] % mod;
          }
      }
    ans += res * k % mod;
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
}

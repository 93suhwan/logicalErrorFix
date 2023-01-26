#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MX = 200005;
template <class T>
void ckmin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T& a, T b) {
  a = max(a, b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < ((int)a.size()); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < (SZ); i++) re(a[i]);
}
}  // namespace input
template <class A>
void rd(vector<A>& v);
template <class T>
void rd(T& x) {
  cin >> x;
}
template <class H, class... T>
void rd(H& h, T&... t) {
  rd(h);
  rd(t...);
}
template <class A>
void rd(vector<A>& x) {
  for (auto& a : x) rd(a);
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
void __p(T a) {
  cout << a;
}
int dp[10000007];
int kk[10000007];
signed main() {
  int n, mod;
  cin >> n >> mod;
  dp[1] = 1;
  long long zz = 0;
  for (int i = 1; i <= n; ++i) {
    kk[i] = (1ll * kk[i] + kk[i - 1]) % mod;
    if (i > 1) dp[i] = kk[i];
    dp[i] = (1ll * dp[i] + zz) % mod;
    for (int j = 2 * i, k = 1; j <= n; j += i, k++) {
      kk[j] = (kk[j] + dp[i]) % mod;
      kk[j + k + 1] = (kk[j + k + 1] + mod - dp[i]) % mod;
    }
    zz = (dp[i] + zz) % mod;
  }
  cout << dp[n];
}

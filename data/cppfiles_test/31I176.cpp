#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod;
const long long maxn = 100005;
long long n, a[maxn], b[maxn];
void orzck() {
  cin >> n;
  for (long long i = (0); i < ((long long)(n)); i++) cin >> a[i];
  for (long long i = (0); i < ((long long)(n)); i++) b[i] = 0;
  for (long long i = (0); i < ((long long)(n - 1)); i++) {
    if (abs(b[n - 1] + a[i]) <= 10000) {
      b[n - 1] += a[i];
      b[i] += -a[n - 1];
    } else {
      b[n - 1] += -a[i];
      b[i] += a[n - 1];
    }
  }
  for (long long i = (0); i < ((long long)(n)); i++) cout << (b[i]) << ' ';
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  cin >> t;
  while (t--) orzck();
  return 0;
}

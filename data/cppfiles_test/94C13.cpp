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
const long long MOD = Mod2;
const long long maxn = (1ll << (20)) + 5;
long long n, res;
vector<long long> vec;
void orzck() {
  cin >> n;
  res = 0;
  vec.clear();
  for (long long i = (0); i < ((long long)(10)); i++) {
    vec.push_back(n % 10);
    n /= 10;
  }
  for (long long mask = (0); mask < ((long long)((1ll << (8)))); mask++) {
    long long cnt = 1;
    for (long long i = (0); i < ((long long)(10)); i++) {
      long long x = vec[i] - (i >= 2 ? (mask >> (i - 2) & 1) : 0);
      if (mask >> i & 1) x += 10;
      cnt *= (x <= 9 ? x + 1 : 19 - x);
    }
    res += cnt;
  }
  print(res - 2);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  cin >> t;
  while (t--) orzck();
  return 0;
}

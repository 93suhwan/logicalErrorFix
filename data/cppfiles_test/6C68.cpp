#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const double eps = (1e-9);
const long long oo = (long long)(1e18 + 5);
vector<int> divs[(long long)(1e5 + 5)];
int occ[(long long)(1e5 + 5)];
int sz_occ;
bool prime[(long long)(1e5 + 5)];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < (long long)(1e5 + 5); i++)
    for (int j = i; j < (long long)(1e5 + 5); j += i) divs[j].push_back(i);
  prime[1] = 1;
  for (int i = 2; i < (long long)(1e5 + 5); i++)
    if (!prime[i])
      for (int j = 2 * i; j < (long long)(1e5 + 5); j += i) prime[j] = 1;
  vector<long long> mul((long long)(1e5 + 5));
  mul[1] = 1;
  for (int i = 2; i < (long long)(1e5 + 5); i++) {
    mul[i] = i;
    for (auto d : divs[i])
      if (d != i) mul[i] -= mul[d];
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  vector<long long> first((long long)(1e5 + 5));
  for (int i = 1; i <= n; i++) {
    sz_occ = 0;
    for (int j = i; j <= n; j += i)
      for (auto d : divs[a[j - 1]]) {
        if (!first[d]) {
          occ[sz_occ] = d;
          sz_occ++;
        }
        first[d]++;
      }
    for (int j = 0; j < sz_occ; j++) {
      ans += first[occ[j]] * first[occ[j]] * mul[occ[j]] * mul[i];
      first[occ[j]] = 0;
    }
  }
  cout << (ans % mod) << '\n';
  return 0;
}

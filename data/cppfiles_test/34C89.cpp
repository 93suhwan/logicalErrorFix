#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
long long power(long long x, long long y, long long M) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
const long long mxn = 1e6 + 6, mod = 1e9 + 7, inf = 1e18;
long long t, casee = 1;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> possiblesubsetxor(8500, vector<long long>());
  for (long long i = 0; i < 8500; i++) possiblesubsetxor[i].push_back(0);
  vector<long long> pos(8500, 0);
  vector<long long> help(8500, 8500);
  pos[0] = 1;
  help[0] = 0;
  for (long long i = 0; i < n; i++) {
    for (long long currxor : possiblesubsetxor[a[i]]) {
      long long newxor = currxor ^ a[i];
      pos[newxor] = 1;
      if (a[i] < help[newxor]) {
        for (long long k = a[i] + 1; k < help[newxor]; k++) {
          possiblesubsetxor[k].push_back(newxor);
        }
        help[newxor] = a[i];
      }
    }
    possiblesubsetxor[a[i]].clear();
  }
  long long cnt = 0;
  for (long long i = 0; i < 8500; i++) cnt += pos[i];
  cout << cnt << "\n";
  for (long long i = 0; i < 8500; i++) {
    if (pos[i]) cout << i << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    test_case();
    casee++;
  }
  return 0;
}

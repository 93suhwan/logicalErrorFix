#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chmax(T &x, T &y) {
  if (x < y) swap(x, y);
}
template <class T>
inline void chmin(T &x, T &y) {
  if (x > y) swap(x, y);
}
const long long INF = 0x3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const double EPS = 10e-10;
const long long P2LIM = (long long)2e18;
const long long maxN = 1e9 + 10;
void Solution() {}
long long countSC(long long N) {
  long long res =
      (long long)sqrt(N) + (long long)cbrt(N) - (long long)(sqrt(cbrt(N)));
  return res;
}
int32_t main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    cout << countSC(n) << '\n';
  }
  return 0;
}

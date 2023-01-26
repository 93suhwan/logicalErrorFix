#include <bits/stdc++.h>
#pragma GCC optimise("Os")
#pragma GCC optimise("O3")
#pragma GCC optimise("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC target("sse4")
using namespace std;
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename T1, typename T2>
long long int fastpow(long long int base, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= base;
    }
    base *= base;
    n = n >> 1;
  }
  return res;
}
void sync() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  bool first = true;
  os << "[";
  for (unsigned long long int i = 0; i < v.size(); i++) {
    if (!first) os << ",";
    cout << v[i];
    first = false;
  }
  return os << "]";
}
class Solution {
 public:
  void solve();
};
signed main() {
  sync();
  long long int t = 1;
  Solution ob;
  cin >> t;
  while (t--) ob.solve();
  return 0;
}
void Solution::solve() {
  long long int n;
  cin >> n;
  cout << (-1 * n) + 1 << " " << n << "\n";
  return;
}

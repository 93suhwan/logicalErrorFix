#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long MOD = 1e9 + 7;
const long long inf = 1e8;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    n >>= 1;
  }
  return res;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int min_el = a[0];
    for (auto x : a) min_el &= x;
    cout << min_el << endl;
  }
}

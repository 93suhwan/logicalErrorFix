#include <bits/stdc++.h>
using namespace std;
const int N = 60, mod = 1e9 + 7;
vector<long long> a;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long res = 6 * (ksm(4, (1ll << n) - 2)) % mod;
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}

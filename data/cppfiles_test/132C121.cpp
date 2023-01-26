#include <bits/stdc++.h>
using namespace std;
const std::int_fast64_t mod = 1e9 + 7;
std::int_fast64_t gcd(std::int_fast64_t a, std::int_fast64_t b) {
  if (b == 0)
    return a;
  else
    return abs(gcd(b, a % b));
}
bool isPrime(std::int_fast64_t n) {
  if (n <= 1) {
    return 0;
  }
  for (std::int_fast64_t i = 2; i <= sqrt(n); ++i)
    if (n % i == 0) return 0;
  return 1;
}
using namespace std;
void solve() {
  vector<int> v(7);
  for (auto& a : v) cin >> a;
  int k = v[0];
  int m = v[1];
  int d = v[6] - k - m;
  cout << k << " " << m << " " << d << " "
       << "\n";
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i{0}, tcc = 1; i < t; ++i, ++tcc) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
int const len = 2e5 + 1;
long long const mod = 998244353;
long long const inf = 2e12 + 7;
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return gcd(b, a % b);
}
void test_case() {
  long long x, y;
  cin >> x >> y;
  if (x > y)
    cout << x + y << "\n";
  else if (x < y)
    cout << (x + y) / 2 << "\n";
  else
    cout << x << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) test_case();
}

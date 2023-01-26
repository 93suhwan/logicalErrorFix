#include <bits/stdc++.h>
using namespace std;
const unsigned int mod = 1000000007;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void f(long long n) {
  for (int i = 3; i <= n; i += 2) {
    if (gcd(i, (n - i)) == 1) {
      cout << i << " " << (n - i) << " ";
      return;
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  long long c = 1;
  if (n % 2 == 0) {
    n--;
    long long a = n / 2;
    long long b = n - a;
    cout << a << " " << b << " " << c << "\n";
  } else {
    n--;
    f(n);
    cout << c << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

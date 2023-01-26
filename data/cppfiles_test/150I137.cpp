#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 123;
const long long MAX = 1000000;
const long long MOD = 1000000007;
const long double pi = 3.1415926536;
bool isPrime(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (auto i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
long long cc(long long ans) {
  long long cc = (ans * (ans + 1)) / 2;
  return cc;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void f() {
  long long n;
  cin >> n;
  long long a[n];
  for (auto i = 0; i < n; i++) cin >> a[i];
  long long c1 = 0, c2 = 0;
  sort(a, a + n);
  long long ans = a[n - 1] / 3;
  for (auto i = 0; i < n; i++) {
    if (a[i] % 3 == 1)
      ++c1;
    else if (a[i] % 3 == 2)
      ++c2;
  }
  if ((a[n - 1] % 3 == 0) && (c1 || c2)) ++ans;
  if ((a[n - 1] % 3 == 2)) {
    ans++;
    if (c1) ++ans;
  }
  if (a[n - 1] % 3 == 1) {
    ++ans;
    if (c2) {
      if (a[0] == 1 || (a[n - 2] == (a[n - 1] - 1))) ++ans;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    f();
  }
}

#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool IsPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return (s == t);
}
long double ipow(long double x, long long y) {
  long double temp;
  if (y == 0) return 1;
  temp = ipow(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void precompute() {}
long long XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long dx[] = {-1LL, 0LL, 1LL, 0LL};
long long dy[] = {0LL, 1LL, 0LL, -1LL};
string tot = "abcdefghijklmnopqrstuvwxyz";
void G() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long a[n];
  long long s = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], s += a[i];
  if (k == 0) {
    cout << s << "\n";
    return;
  }
  sort(a, a + n);
  long long x = (n - k - 1);
  long long y = n - 1;
  long long sum = 0;
  for (long long i = 0; i < n - 2 * k; i++) sum += a[i];
  for (long long w = 0; w < k; w++) {
    long long num = a[x--] / a[y--];
    sum += num;
  }
  cout << sum << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  precompute();
  long long tc;
  cin >> tc;
  while (tc--) {
    G();
  }
  return 0;
}

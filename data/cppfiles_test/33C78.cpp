#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else {
    if (n % 2 == 0)
      return (power(a, n / 2) % 1000000007 * power(a, n / 2) % 1000000007) %
             1000000007;
    else
      return (power(a, n / 2) % 1000000007 * power(a, n / 2) % 1000000007 * a) %
             1000000007;
  }
}
bool poweroftwo(int x) { return x && (!(x & (x - 1))); }
long long int cmpi(pair<long long int, long long int> a,
                   pair<long long int, long long int> b) {
  return a.first < b.first;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int search(long long int a[], long long int n, long long int x) {
  long long int l = 0, r = n - 1;
  if (x < a[l] || x > a[r]) return -1;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (a[mid] == x) return 1;
    if (a[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
long long int isprime(long long int x) {
  long long int flag = 0;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      flag++;
      break;
    }
  }
  if (flag) return 1;
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = LLONG_MIN;
  for (long long int i = 1; i < n - 1; i++) {
    ans = max(ans, max(min(a[i], a[i - 1]) * max(a[i], a[i - 1]),
                       min(a[i], a[i + 1]) * max(a[i], a[i + 1])));
  }
  ans = max(ans, a[0] * a[1]);
  ans = max(ans, a[n - 1] * a[n - 2]);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}

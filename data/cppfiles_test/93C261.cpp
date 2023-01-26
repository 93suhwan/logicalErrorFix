#include <bits/stdc++.h>
const int N = 1000001;
using namespace std;
long long int power(long long int a, long long int b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long int x = power(a, b / 2);
    return x * x;
  } else {
    long long int x = power(a, (b - 1) / 2);
    return x * x * a;
  }
}
long long int fun(long long int n) {
  long long int sum = 0;
  while (n > 1) {
    sum++;
    n /= 2;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    long long int r = fun(n);
    long long int x = fun(2 * k);
    long long int ans = x;
    long long int y = power(2, x);
    long long int z = n - y;
    if (z >= 0) {
      ans += (z / k);
      if (z % k != 0) ans++;
    } else {
      ans = r;
      if (power(2, r) != n) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}

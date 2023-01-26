#include <bits/stdc++.h>
using namespace std;
vector<long long int> divisor;
void getDivisors(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisor.push_back(i);
      else {
        divisor.push_back(i);
        divisor.push_back(n / i);
      }
    }
  }
}
long long int power(long long int a, long long int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  long long int temp = power(a, n / 2);
  if (n % 2 == 0) {
    return ((temp % 1000000007) * (temp % 1000000007)) % 1000000007;
  } else {
    return ((((temp % 1000000007) * (temp % 1000000007)) % 1000000007) * a) %
           1000000007;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<vector<long long int>> a(2, vector<long long int>(n + 50));
    for (int i = 0; i < 2; i = i + 1)
      for (int j = 0; j < n; j = j + 1) cin >> a[i][j];
    long long int left = 0, right = 0;
    for (int i = 1; i < n; i = i + 1) right += a[0][i];
    long long int sum = 0;
    for (int i = 0; i < n - 1; i = i + 1) sum += a[1][i];
    long long int ans = 1e18;
    for (int i = 0; i < n; i = i + 1) {
      long long int bob = max(left, right);
      long long int alice = sum;
      if (bob <= alice) ans = min(ans, bob);
      left += a[1][i];
      right -= a[0][i + 1];
      sum -= a[1][i];
      sum += a[0][i + 1];
    }
    if (ans == 1e18) {
      cout << 0 << endl;
    } else
      cout << ans << endl;
  }
}

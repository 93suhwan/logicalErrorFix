#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res % 1000000007;
}
long long int abc(long long int n, long long int k) {
  if (n == 1) return power(2, k);
  if (k == 0) return 1;
  if (n % 2 == 0 && k == 1) return power(2, n - 1);
  if (n & 1) {
    long long int x = power(2, n - 1);
    x++;
    x = power(x, k);
    return x;
  } else {
    long long int x = power(2, k - 1);
    x = x + power(2, n - 1) * (abc(n, k - 1)) + 1;
    x %= 1000000007;
    return x;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long int n, k;
    cin >> n >> k;
    cout << abc(n, k) << '\n';
  }
}

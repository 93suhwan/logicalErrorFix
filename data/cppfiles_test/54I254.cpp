#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (a > 0) {
    if (a & 1) res = (res * b) % 1000000007;
    b = (b * b) % 1000000007;
    a /= 2;
  }
  return res;
}
long long int abc(long long int n, long long int k) {
  if (n == 1) return power(2, k);
  if (k == 0) return 1;
  if (!n & 1) {
    long long int x = power(2, n - 1);
    x++;
    x = power(x, k);
    return x;
  } else {
    long long int x = power(2, k - 1);
    x = x + power(2, n - 1) * (abc(n, k - 1));
    x++;
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

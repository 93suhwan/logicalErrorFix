#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return ((power(a, b / 2) % 1000000007) * (power(a, b / 2) % 1000000007) %
            1000000007);
  else
    return ((a * (power(a, b / 2) % 1000000007) % 1000000007) *
            (power(a, b / 2) % 1000000007) % 1000000007);
}
int main() {
  long long k;
  cin >> k;
  long long num = 0, c = 2;
  for (int i = 2; i <= k; i++) {
    num = (num + c) % 1000000007;
    c = (c % 1000000007 * 2) % 1000000007;
  }
  num %= 1000000007;
  long long ans = 6;
  ans = (ans * power(4, num)) % 1000000007;
  cout << ans << endl;
  return 0;
}

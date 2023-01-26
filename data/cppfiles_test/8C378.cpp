#include <bits/stdc++.h>
using namespace std;
long long int binExp(long long int x, long long int n, long long int m) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}
long long int modInv(long long int i, long long int m) {
  return binExp(i, m - 2, m);
}
long long int add(long long int a, long long int b) {
  long long int res = a + b;
  if (res >= 1000000007) res -= 1000000007;
  if (res < 0) res += 1000000007;
  return res;
}
long long int mul(long long int a, long long int b) {
  long long int res = (a) * (b);
  res %= 1000000007;
  if (res < 0) res += 1000000007;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << " " << n / 3 << endl;
    } else {
      cout << n / 3 << " " << n / 3 + 1 << endl;
    }
  }
  return 0;
}

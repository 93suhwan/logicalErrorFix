#include <bits/stdc++.h>
const long long mod = 1000000;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long num, k;
    cin >> num >> k;
    long long count = 0;
    long long i = 1;
    if (num == 1)
      cout << "0" << endl;
    else {
      while (i <= k) {
        count++;
        i = i * 2;
      }
      num = num - i;
      if (num == 0 || num < 0)
        cout << count << endl;
      else {
        if (num % k != 0) count += (num / k) + 1;
        if (num % k == 0) count += num / k;
        cout << count << endl;
      }
    }
  }
  return 0;
}

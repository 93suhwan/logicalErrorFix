#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long binopow(long long b, long long pow) {
  if (pow == 0) return 1;
  long long ans;
  ans = binopow(b, pow / 2);
  ans = (ans * ans) % mod;
  if (pow % 2) ans = (ans * b) % mod;
  return ans;
}
long long inv(long long a, long long mod) { return binopow(a, mod - 2); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<int> v;
    while (k > 0) {
      v.push_back(k % 2);
      k = k / 2;
    }
    long long ans = 0;
    long long j = 1;
    for (int i = 0; i < v.size(); i++) {
      ans = ans + (v[i] * j) % mod;
      ans = ans % mod;
      j = j * n;
    }
    cout << ans << "\n";
  }
}

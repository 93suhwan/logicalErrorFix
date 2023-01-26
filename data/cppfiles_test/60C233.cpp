#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long mod1 = 998244353;
long long fastpower(long long base, long long power) {
  long long res = 1;
  while (power > 0) {
    if (power & 1) res = res * base % mod;
    power >>= 1;
    base = base * base % mod;
  }
  return res;
}
long long t, n, a[1000000];
int main() {
  cin >> t;
  while (t--) {
    long long cnt = 0;
    long long sum = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sum *= 2;
    if (sum % n) {
      cout << 0 << endl;
      continue;
    }
    sum /= n;
    for (int i = 0; i < n; i++) cnt += mp[sum - a[i]], mp[a[i]]++;
    cout << cnt << endl;
  }
  return 0;
}

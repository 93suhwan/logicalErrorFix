#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c() {}
long long power(long long base, long long n, long long mod) {
  long long ans = 1;
  while (n != 0) {
    if (n % 2) {
      ans = (ans * base) % mod;
      n = n - 1;
    } else {
      base = (base * base) % mod;
      n = n / 2;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  c_p_c();
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long p = log2(k);
    long long x = pow(2, p + 1);
    if (n == 1 && k == 1) {
      cout << "0" << endl;
    } else if (n < x) {
      cout << p + 1 << endl;
    } else {
      long long y = (n - x) / k;
      if ((n - x) % k) {
        y++;
      }
      cout << p + 1 + y << endl;
    }
  }
}

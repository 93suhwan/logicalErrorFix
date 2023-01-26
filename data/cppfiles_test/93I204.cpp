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
    long long n, k, x, t;
    cin >> n >> k;
    x = 0;
    x = (long long)floor(log2(k));
    if (n > (long long)pow(2, x)) {
      n = n - 2 * (long long)pow(2, x);
      t = x + 1;
      if (n > 0) t += (ceil)((double)n / k);
    } else {
      t = x;
    }
    cout << t << "\n";
  }
}

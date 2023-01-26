#include <bits/stdc++.h>
using namespace std;
long long dp[1001];
bool ready[1001];
bool used[1001];
long double dist(pair<long long, long long> p1, pair<long long, long long> p2) {
  return sqrt((p2.first - p1.first) * (p2.first - p1.first) +
              (p2.second - p1.second) * (p2.second - p1.second));
}
string repeat(long long t, string s) {
  string ans;
  for (long long i = 0; i < t; i++) {
    ans += s;
  }
  return ans;
}
long long bin_mod_exp(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a % 1000000007;
  }
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((res % 1000000007) * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << bin_mod_exp(2LL, k) << endl;
    return;
  }
  if (!k) {
    cout << 1 << endl;
    return;
  }
  if (n % 2 == 0) {
    long long a = bin_mod_exp(bin_mod_exp(2LL, n - 1) + 1, 1000000007 - 2);
    long long ans = ((bin_mod_exp(2LL, n * k) -
                      bin_mod_exp(bin_mod_exp(2LL, n - 1) - 1, k)) *
                         a +
                     bin_mod_exp(bin_mod_exp(2LL, n - 1) - 1, k)) %
                    1000000007;
    while (ans < 0) {
      ans += 1000000007;
    }
    cout << ans << endl;
  } else {
    cout << bin_mod_exp(bin_mod_exp(2LL, n - 1) + 1, k) << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

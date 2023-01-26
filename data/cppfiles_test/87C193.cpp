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
  long long n;
  cin >> n;
  long long ans = 0;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long p = 1;
  for (long long i = 0; i < n; i++) {
    if (a[i] > i + p) {
      ans += a[i] - i - p;
      p += a[i] - i - p;
    }
  }
  cout << ans << endl;
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

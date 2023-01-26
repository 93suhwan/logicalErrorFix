#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
using namespace std;
const int INF = 1000 * 1000 * 1000;
const int MOD = 998244353;
const double EPS = 0.000000001;
const long long inf = (long long)1e18;
void run_case() {
  int n;
  cin >> n;
  int cur = 1;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    if (i && v[i] == 0 && v[i - 1] == 0) {
      cout << -1 << "\n";
      return;
    }
    if (v[i]) {
      if (i == 0 || v[i - 1] == 0)
        cur++;
      else
        cur += 5;
    }
  }
  cout << cur << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    run_case();
  }
  return 0;
}

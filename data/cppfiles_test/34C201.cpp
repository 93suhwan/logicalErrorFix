#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<long long>;
using vii = vector<pair<long long, long long> >;
const long long INFI = 1e9 + 228;
const ll INFL = 1e18 + 228;
const ld INFLD = 1e18 + 228;
const ld PI = acos(-1);
const long long MAXN = 1e5 + 228;
vii DD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void run() {
  long long n, k;
  cin >> n >> k;
  vi mass;
  mass.push_back(0);
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    mass.push_back(x);
  }
  long long ans = -INFL;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = n; j >= i + 1 && i * j >= n * (n - 1) - 2 * n * k; --j) {
      ans = max(ans, i * j - k * (mass[i] | mass[j]));
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) run();
  return 0;
}

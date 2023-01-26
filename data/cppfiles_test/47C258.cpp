#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1000000007;
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline int LCM(int x, int y) { return x / gcd(x, y) * y; }
void cases() {
  int n, k;
  cin >> n >> k;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) a.push_back(x);
    if (x < 0) b.push_back(-x);
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  long long int ans = 0;
  for (int i = a.size() - 1; i >= 0; i -= k) ans += 2 * a[i];
  for (int i = b.size() - 1; i >= 0; i -= k) ans += 2 * b[i];
  int mx = 0;
  if (a.size() > 0) mx = a[a.size() - 1];
  if (b.size() > 0) mx = max(b[b.size() - 1], mx);
  ans -= mx;
  cout << ans << "\n";
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cases();
  }
  return 0;
}

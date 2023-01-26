#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long powerMod(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * powerMod(a * a % md, b / 2, md) % md
                      : powerMod(a * a % md, b / 2, md) % md));
}
long long modInv(long long x, long long m) { return powerMod(x, m - 2, m); }
const long long INF = 1e18;
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  int extra = 0;
  set<pair<int, int>> s;
  map<int, int> m1;
  for (int i = 0; i < n; i++) {
    if (m[a[i]] > k) {
      m1[a[i]] = m[a[i]] - k;
      extra += m[a[i]] - k;
      m[a[i]] = 0;
    }
  }
  int t = n - extra;
  int f = (t / k) * k;
  int ans[n];
  int c = 0;
  int j = 1;
  for (int i = 0; i < n; i++) {
    if (j == k + 1) j = 1;
    if (m1[a[i]]) {
      ans[i] = 0;
      m1[a[i]]--;
    } else if (c >= f)
      ans[i] = 0;
    else if (c < f) {
      ans[i] = j++;
      c++;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

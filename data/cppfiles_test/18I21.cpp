#include <bits/stdc++.h>
using namespace std;
long long fpow(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r *= x;
    x *= x;
    y >>= 1;
  }
  return r;
}
const long long mod = 1000000007;
const unsigned long long INF = 1000000000000000000;
const long long N = 1000007;
bool intersect(pair<long long, long long> seg1,
               pair<long long, long long> seg2) {
  if (seg1.first > seg2.first) swap(seg1, seg2);
  return (seg1.second > seg2.first && seg2.second > seg1.second);
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> seg;
  vector<bool> unused(2 * n + 1, true);
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    seg.push_back({x, y});
    unused[x] = false, unused[y] = false;
  }
  vector<long long> rempoints;
  for (long long i = 1; i <= 2 * n; i++) {
    if (unused[i]) rempoints.push_back(i);
  }
  for (long long i = 0; i < n - k; i++) {
    seg.push_back({rempoints[i], rempoints[n - k + i]});
  }
  long long ans = 0;
  for (long long i = 0; i < 2 * n; i++) {
    for (long long j = i + 1; j < 2 * n; j++) {
      ans += (intersect(seg[i], seg[j]));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

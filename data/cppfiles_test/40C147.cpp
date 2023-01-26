#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 3e5, M = N;
void chmax(int &a, int &b) { a = max(a, b); }
void chmin(long long &a, long long &b) { a = min(a, b); }
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % MOD;
    y = y / 2, x = (x * x) % MOD;
  }
  return res % MOD;
}
int maxSubArraySum(int a[], int size) {
  int max_so_far = INT_MIN, max_ending_here = 0;
  for (int i = 0; i < size; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
void solve() {
  int m;
  cin >> m;
  int a[m], b[m], pra[m + 1], prb[m + 1], sa[m + 1], sb[m + 1];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (i)
      prb[i] = prb[i - 1] + b[i];
    else
      prb[i] = b[i];
  }
  if (m == 1) {
    cout << 0 << '\n';
    return;
  }
  for (int i = m - 1; i >= 0; i--) {
    if (i != m - 1)
      sa[i] = sa[i + 1] + a[i];
    else
      sa[i] = a[i];
  }
  int x = 0;
  int ans = INT_MAX;
  while (x < m) {
    if (x == 0)
      ans = min(ans, max(sa[x + 1], 0));
    else if (x == m - 1)
      ans = min(ans, max(0, prb[x - 1]));
    else
      ans = min(ans, max(sa[x + 1], prb[x - 1]));
    x++;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

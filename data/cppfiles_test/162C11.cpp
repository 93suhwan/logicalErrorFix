#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long n;
long long h[long long(2e5 + 10)];
bool check(long long x) {
  vector<int> cur_h(h, h + n);
  for (int i = n - 1; i >= 2; i--) {
    if (cur_h[i] < x) return false;
    long long d = min(h[i], cur_h[i] - x) / 3;
    cur_h[i - 1] += d;
    cur_h[i - 2] += 2 * d;
  }
  return cur_h[0] >= x and cur_h[1] >= x;
}
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> h[i];
  }
  long long l = 0, r = *max_element(h, h + n);
  while (l < r) {
    long long mid = l + (r - l + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
bool check(long long mid, vector<long long> nar, vector<long long> &org) {
  for (long long i = ((long long)(nar).size()) - 1; i >= 2; i--) {
    if (nar[i] < mid) return false;
    long long k = min(nar[i] - mid, org[i]);
    k /= 3;
    nar[i] -= 3 * k;
    nar[i - 1] += k;
    nar[i - 2] += 2 * k;
  }
  for (auto &it : nar) {
    if (it < mid) return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> ar(n);
  for (auto &it : ar) cin >> it;
  long long ans = 0;
  long long lo = 0, hi = 1e9;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid, ar, ar)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";
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

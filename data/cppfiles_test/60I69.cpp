#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  double k = 0;
  for (auto i : a) k += i;
  k = (k * 2.0) / (double)n;
  map<long long, long long> c;
  for (auto i : a) c[i] += 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    c[a[i]] -= 1;
    ans += c[k - a[i]];
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

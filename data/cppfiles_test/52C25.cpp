#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) sum += a[i];
  cout << setprecision(20) << fixed
       << 1.0 * a[n - 1] + (sum * 1.0 / (n * 1.0 - 1)) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}

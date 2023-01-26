#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  double sum = 0;
  for (int i = 0; i < n - 1; i++) sum += a[i];
  cout << setprecision(20) << fixed << a[n - 1] + (sum / (n - 1)) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000000001;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  cin >> a[0];
  long long max = 0;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i] * a[i - 1] > max) max = a[i] * a[i - 1];
  }
  cout << max << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

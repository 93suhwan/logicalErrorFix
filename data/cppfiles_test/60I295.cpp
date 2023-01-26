#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mini = min(mini, a[i]);
    }
    long long ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      ans = min(ans, mini & a[i]);
    }
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  solve();
  cout << fixed;
  return 0;
}

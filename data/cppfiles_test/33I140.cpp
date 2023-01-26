#include <bits/stdc++.h>
using namespace std;
static bool compare(long long a, long long b) { return a > b; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n, 0);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long mn = 0, mx = 1;
  long long ans = v[mx] * v[mn];
  if (v[0] > v[1]) swap(mn, mx);
  long long i = 2;
  for (long long i = 2; i < n; i++) {
    if (v[i] >= v[mx]) {
      mx = i;
      ans = max(ans, v[mn] * v[mx]);
    } else if (v[i] > v[mn] && v[i] < v[mx]) {
      mn = i;
      while (mn - mx > 1) mx++;
      ans = max(ans, v[mn] * v[mx]);
    } else if (v[i] <= v[mn]) {
      mn = i;
      ans = max(ans, v[mn] * v[mx]);
    }
    while (mx - mn > 1) {
      mn++;
      ans = max(ans, v[mn] * v[mx]);
    }
  }
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

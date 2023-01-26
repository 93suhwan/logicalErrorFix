#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, d = INT_MIN, second = 0;
    double e, ans;
    cin >> n;
    long long int ar[n];
    for (i = 0; i < n; i++) {
      cin >> ar[i];
      d = max(d, ar[i]);
      second = second + ar[i];
    }
    second = second - d;
    e = (second * 1.0) / (n - 1);
    ans = e + d;
    cout << fixed << setprecision(9);
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}

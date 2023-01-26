#include <bits/stdc++.h>
using namespace std;
long double M = 1e12;
void solve() {
  long double n;
  cin >> n;
  long double maxi = -M, sum = 0;
  vector<long double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    maxi = max(maxi, a[i]);
  }
  long double x = maxi;
  long double y = (sum - maxi) / (n - 1);
  long double ans = x + y;
  cout << fixed << setprecision(9);
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

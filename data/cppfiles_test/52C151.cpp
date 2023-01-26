#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
bool iseven(long long int n) { return (n >= 0 && n % 2 == 0); }
void solve() {
  long long int n;
  cin >> n;
  long long int a[n], maxi;
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0) maxi = a[0];
    sum += (double)a[i];
    maxi = max(maxi, a[i]);
  }
  double ans;
  ans = (double)maxi;
  sum -= (double)maxi;
  ans += sum / ((double)(n - 1));
  cout << setprecision(9) << ans << "\n";
}
int main() {
  long long int t;
  cin >> t;
  while (t--) solve();
}

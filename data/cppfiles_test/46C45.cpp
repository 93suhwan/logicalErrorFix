#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0, cur = a[n - 1];
  long long mx = (*max_element((a).begin(), (a).end()));
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] > cur) {
      cur = a[i];
      ans++;
    }
    if (a[i] == mx) {
      break;
    }
  }
  cout << ans << endl;
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}

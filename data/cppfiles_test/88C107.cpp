#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
const double PI = 4 * atan(1);
string solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n % 2 == 0) return "YES";
  for (long long int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) return "YES";
  }
  return "NO";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}

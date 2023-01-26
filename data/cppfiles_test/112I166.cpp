#include <bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX;
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<long long> arr = {a, b, c};
  sort(arr.begin(), arr.end());
  long long mx = a + b + c - 3;
  long long mi = arr[2] - arr[1] - arr[0] - 1;
  if (m >= mi and m <= mx) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

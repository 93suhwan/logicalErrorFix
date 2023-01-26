#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long c1 = 0, c0 = 0;
  for (long long i = 0; i < n; i++) {
    if (arr[i] == 0) c0++;
    if (arr[i] == 1) c1++;
  }
  if (c0 == 0) {
    cout << c1 << endl;
    return;
  }
  cout << (pow(2, c0) * c1) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  bool flag = 0;
  long long mn = INT_MAX;
  for (long long i(0); i < n; i++) {
    cin >> arr[i];
    mn = min(mn, arr[i]);
    if (arr[i] % 2 == 0) flag = 1;
  }
  if (flag == 1) {
    cout << "0"
         << "\n";
  } else
    cout << mn << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
}

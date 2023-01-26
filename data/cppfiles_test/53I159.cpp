#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int cnt = 1;
  for (long long int i = 1; i < n; i++) {
    if (v[i] <= v[i - 1]) {
      cnt++;
    }
  }
  if (cnt <= k) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

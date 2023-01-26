#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, v[i] * v[i - 1]);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  bool multiple_testcases = 1;
  if (multiple_testcases) cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}

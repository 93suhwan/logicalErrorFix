#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n, t, a, b, x, y;
  string s, f;
  long long ans;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> as;
    for (int i = 0; i < n; i++) {
      cin >> a;
      as.push_back(a);
    }
    sort(as.begin(), as.end());
    long long ans = as[0];
    long long q = as[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, as[i] - q);
      q += as[i] - q;
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, v[i] * v[i + 1]);
    }
    cout << ans << endl;
  }
  return 0;
}

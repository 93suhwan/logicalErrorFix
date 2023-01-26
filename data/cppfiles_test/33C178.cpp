#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    long long number = 0;
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      number = 1LL * v[i] * v[i + 1];
      ans = max(number, ans);
    }
    cout << ans << '\n';
  }
}

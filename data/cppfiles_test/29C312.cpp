#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    long long c1 = 0, c0 = 0;
    for (i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 1) c1++;
      if (v[i] == 0) c0++;
    }
    long long ans = c1 + c1 * (((long long)1 << c0) - 1);
    cout << ans << "\n";
  }
}

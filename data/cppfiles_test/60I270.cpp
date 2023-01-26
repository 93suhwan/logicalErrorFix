#include <bits/stdc++.h>
using namespace std;
int main() {
  int qq;
  cin >> qq;
  while (qq--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans = min(ans, v[i] & v[j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

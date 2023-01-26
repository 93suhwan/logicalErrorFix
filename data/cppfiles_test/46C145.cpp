#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int ans = 0;
    int r = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (v[i] > r) {
        r = v[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
}

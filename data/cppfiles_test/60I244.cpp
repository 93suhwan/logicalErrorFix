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
    int mini = *min_element(v.begin(), v.end());
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      ans = min(ans, v[i] & mini);
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, n, k, ans = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    while (k--) {
      int i1 = *min_element(v.begin(), v.end());
      int i2 = *max_element(v.begin(), v.end());
      v.erase(min_element(v.begin(), v.end()));
      v.erase(max_element(v.begin(), v.end()));
      ans += floor(i1 / i2);
    }
    ans += accumulate(v.begin(), v.end(), 0);
    cout << ans << endl;
  }
}

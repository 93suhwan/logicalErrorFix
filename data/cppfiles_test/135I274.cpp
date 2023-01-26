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
      int i1 = *max_element(v.begin(), v.end());
      v.erase(max_element(v.begin(), v.end()));
      int i2 = *max_element(v.begin(), v.end());
      ans += floor(i2 / i1);
      v.erase(max_element(v.begin(), v.end()));
    }
    ans += accumulate(v.begin(), v.end(), 0);
    cout << ans << endl;
  }
}

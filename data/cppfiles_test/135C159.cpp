#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int index = n - 1, flag = 0;
    for (int i = 0; i < k; i++) {
      ans += (v[index - k] / v[index]);
      index -= 1;
    }
    for (int i = 0; i < n - 2 * k; i++) ans += v[i];
    cout << ans << endl;
  }
}

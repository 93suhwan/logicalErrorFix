#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int n, x, i;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    bool flag = false;
    for (i = 0; i < n - 1; i++) {
      if (v[i] == 0 && v[i + 1] == 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    long long ans = 1;
    if (v[0]) ans++;
    for (i = 1; i < n; i++) {
      if (v[i - 1] == 1 && v[i] == 1)
        ans += 5;
      else if (v[i] == 1)
        ans += 1;
    }
    cout << ans << endl;
  }
  return 0;
}

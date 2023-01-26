#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int_fast64_t t;
  cin >> t;
  while (t--) {
    int_fast64_t a, c;
    cin >> a >> c;
    if (c < a) {
      cout << "-1\n";
      continue;
    }
    int_fast64_t c1 = c;
    vector<int_fast64_t> ans;
    bool ok = true;
    while (a && c1) {
      int_fast64_t aD = a % 10;
      int_fast64_t cD = c1 % 10;
      a /= 10;
      c1 /= 10;
      if (cD < aD) {
        cD += (c1 % 10) * 10;
        c1 /= 10;
      }
      int_fast64_t delta = cD - aD;
      if (delta < 0 || delta > 9) {
        ok = false;
        break;
      }
      ans.push_back(delta);
    }
    if (!ok)
      cout << "-1\n";
    else {
      if (a) ans.push_back(a);
      if (c1) ans.push_back(c1);
      reverse(ans.begin(), ans.end());
      int_fast64_t num = 0;
      for (auto i : ans) {
        num *= 10;
        num += i;
      }
      if (num > c)
        cout << "-1\n";
      else
        cout << num << '\n';
    }
  }
}

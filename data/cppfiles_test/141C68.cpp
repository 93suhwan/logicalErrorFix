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
    int_fast64_t a1 = a;
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
      if (num < 0)
        cout << "-1\n";
      else {
        int_fast64_t digiCt = 0;
        int_fast64_t sum = 0;
        int_fast64_t b = num;
        while (a1 && b) {
          int_fast64_t aD = a1 % 10;
          int_fast64_t bD = b % 10;
          a1 /= 10;
          b /= 10;
          int_fast64_t x = 1;
          int_fast64_t s1 = aD + bD;
          if (s1 > 9) x = 2;
          for (int_fast64_t i = 1; i <= digiCt; i++) s1 *= 10;
          sum += s1;
          digiCt += x;
        }
        for (int_fast64_t i = 1; i <= digiCt; i++) a1 *= 10;
        sum += a1;
        for (int_fast64_t i = 1; i <= digiCt; i++) b *= 10;
        sum += b;
        if (sum == c)
          cout << num << '\n';
        else
          cout << "-1\n";
      }
    }
  }
}

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
    int_fast64_t numCpy = a;
    vector<int_fast64_t> ans, c1;
    while (a && c) {
      int_fast64_t aDigi = a % 10;
      a /= 10;
      int_fast64_t cDigi = c % 10;
      c1.push_back(cDigi);
      c /= 10;
      if (cDigi < aDigi) {
        cDigi += (c % 10) * 10;
        c1.push_back(c % 10);
        c /= 10;
      }
      int_fast64_t delta = cDigi - aDigi;
      if (delta < 0) break;
      ans.push_back(delta);
    }
    if (a) ans.push_back(a);
    if (c) {
      ans.push_back(c);
      while (c) {
        c1.push_back(c % 10);
        c /= 10;
      }
    }
    reverse(ans.begin(), ans.end());
    int_fast64_t num = 0;
    for (auto i : ans) {
      num *= 10;
      num += i;
    }
    int_fast64_t b = num;
    vector<int_fast64_t> check;
    while (numCpy && num) {
      int_fast64_t a1 = numCpy % 10;
      int_fast64_t b1 = num % 10;
      numCpy /= 10;
      num /= 10;
      int_fast64_t s = a1 + b1;
      while (s) {
        check.push_back(s % 10);
        s /= 10;
      }
    }
    if (num) check.push_back(num);
    if (numCpy) check.push_back(numCpy);
    bool ok = true;
    for (int_fast64_t i = 0; i < check.size(); i++) {
      ok &= check[i] == c1[i];
    }
    if (ok)
      cout << b << '\n';
    else
      cout << "-1\n";
  }
}

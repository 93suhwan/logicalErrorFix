#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  long long odd = 0, even = 0, oc = 5, ec = 5, ans1 = 10, ans2 = 10;
  for (long long i = 0; i < 10; ++i) {
    if (i & 1) {
      oc--;
      if (s[i] == '1') odd++;
    } else {
      ec--;
      if (s[i] == '1' || s[i] == '?') even++;
    }
    if ((odd - even) > ec || (even - odd) > oc) {
      ans1 = (i + 1);
      break;
    }
  }
  odd = 0;
  even = 0;
  oc = 5;
  ec = 5;
  for (long long i = 0; i < 10; ++i) {
    if (i & 1) {
      oc--;
      if (s[i] == '1' || s[i] == '?') odd++;
    } else {
      ec--;
      if (s[i] == '1') even++;
    }
    if ((odd - even) > ec || (even - odd) > oc) {
      ans2 = (i + 1);
      break;
    }
  }
  cout << min(ans1, ans2) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    cout << setprecision(15) << fixed;
    solve();
  }
  return 0;
}

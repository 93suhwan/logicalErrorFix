#include <bits/stdc++.h>
const long long INF = 1000000001;
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t1;
  cin >> t1;
  for (long long q11 = 0; q11 < t1; q11++) {
    long long n;
    string s, t;
    cin >> n >> s >> t;
    vector<string> a = {""};
    long long ans = 0;
    for (long long q = 0; q < n; q++) {
      if (s[q] != t[q]) {
        ans += 2;
        if (!a.back().empty()) {
          a.push_back("");
        }
      } else {
        a.back().push_back(s[q]);
      }
    }
    for (string &f : a) {
      char last = '2';
      for (char q : f) {
        if (last == '2') {
          last = q;
        } else if (last == q) {
          ans += (q == '0');
        } else {
          ans += 2, last = '2';
        }
      }
      ans += (last == '0');
    }
    cout << ans << '\n';
  }
  return 0;
}

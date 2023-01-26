#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    int pan = 0, ans = 1e6;
    vector<char> v;
    string s;
    cin >> n >> s;
    if (s == string(s.rbegin(), s.rend())) {
      cout << 0 << endl;
      continue;
    }
    map<char, int> m;
    for (int i = 0; i < n; i++) m[s[i]] = 1;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      if (m[c]) {
        string ss = "";
        for (int j = 0; j < n; j++) {
          if (s[j] != c) ss += s[j];
        }
        if (ss == string(ss.rbegin(), ss.rend())) {
          pan++;
          v.push_back(c);
        }
      }
    }
    if (pan == 0)
      cout << -1 << endl;
    else {
      for (auto i : v) {
        queue<int> aa, bb;
        int xa = 0, xb = 0, res = 0;
        for (int j = 0; j < n; j++) {
          if (i == s[j]) aa.push(j);
        }
        for (int j = 0; j < n; j++) {
          if (i == s[n - j - 1]) bb.push(j);
        }
        for (int j = 0; j < 2 * n; j++) {
          if (aa.size() == 0 || bb.size() == 0) {
            res += aa.size() + bb.size();
            break;
          } else if (aa.front() - xa == bb.front() - xb) {
            aa.pop();
            bb.pop();
          } else if (aa.front() - xa > bb.front() - xb) {
            bb.pop();
            xb++;
            res++;
          } else {
            aa.pop();
            xa++;
            res++;
          }
        }
        ans = min(ans, res / 2);
      }
      cout << ans << endl;
    }
  }
  return 0;
}

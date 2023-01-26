#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 2e5 + 10;
long long n, k;
set<char> vis;
string tostring(long long x) {
  string res;
  while (x) {
    res = (char)(x % 10 + '0') + res;
    x /= 10;
  }
  return res;
}
void solve() {
  cin >> n >> k;
  if (k == 1) {
    long long val = 1;
    while (val < n) {
      if (val * 10 + 1 >= n) {
        break;
      }
      val = val * 10 + 1;
    }
    if (val * 10 + 1 == n) {
      cout << val * 10 + 1 << '\n';
      return;
    }
    for (int i = 1; i <= 9; i++) {
      if (val * i >= n && val * (i - 1) < n) {
        cout << val * i << '\n';
        return;
      }
    }
  } else {
    string s = tostring(n);
    vis.clear();
    for (int i = 0; i < s.length(); i++) {
      vis.insert(s[i]);
    }
    if (vis.size() == 1) {
      cout << n + 1 << '\n';
      return;
    } else if (vis.size() == 2) {
      cout << n << '\n';
      return;
    }
    char fi = s[0], se = s[1];
    vector<char> ans;
    ans.push_back(fi);
    ans.push_back(se);
    int flag = 1;
    for (int i = 2; i < s.length(); i++) {
      if (fi >= s[i] || se >= s[i]) {
        if (fi >= s[i] && se >= s[i]) {
          ans.push_back(fi < se ? fi : se);
        } else if (fi >= s[i]) {
          ans.push_back(fi);
        } else {
          ans.push_back(se);
        }
      } else {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
      }
      cout << '\n';
    } else {
      se = se + 1;
      ans.clear();
      ans.push_back(fi);
      ans.push_back(se);
      for (int i = 2; i < s.length(); i++) {
        ans.push_back(min(fi, se));
      }
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
      }
      cout << '\n';
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

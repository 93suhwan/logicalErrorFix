#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 123;
int n, k;
string s;
int check(char c) {
  vector<int> v;
  string t = "", bt = "";
  int tot = 0;
  for (int i = 0; i < n; i++)
    if (s[i] != c) {
      v.push_back(i);
      t += s[i];
    } else
      tot++;
  bt = t;
  reverse(bt.begin(), bt.end());
  if (bt != t) {
    return 2e9;
  }
  if ((int)(v.size()) % 2 == 0) {
    int sz = v.size();
    int f = v[sz / 2 - 1];
    int se = v[sz / 2];
    for (int j = f; j <= se; j++)
      if (s[j] == c) tot--;
    for (int i = sz / 2 - 2, j = sz / 2 + 1; i >= 0 && j < sz; i--, j++) {
      int l = v[i];
      int r = v[i + 1];
      int cnta = 0, cntb = 0;
      for (int j = l; j <= r; j++) {
        if (s[j] == c) cnta++;
      }
      l = v[j - 1];
      r = v[j];
      for (int j = l; j <= r; j++) {
        if (s[j] == c) cntb++;
      }
      tot -= min(cnta, cntb) * 2;
    }
  } else {
    int sz = v.size();
    for (int i = sz / 2 - 1, j = sz / 2 + 1; i >= 0 && j < sz; i--, j++) {
      int l = v[i];
      int r = v[i + 1];
      int cnta = 0, cntb = 0;
      for (int j = l; j <= r; j++) {
        if (s[j] == c) cnta++;
      }
      l = v[j - 1];
      r = v[j];
      for (int j = l; j <= r; j++) {
        if (s[j] == c) cntb++;
      }
      tot -= min(cnta, cntb) * 2;
    }
  }
  return tot;
}
void solve() {
  cin >> n;
  cin >> s;
  int ans = n + 1;
  int cnt = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] == s[j]) {
      continue;
    } else {
      cnt = 1;
      ans = min(ans, check(s[i]));
      ans = min(ans, check(s[j]));
      break;
    }
  }
  if (cnt > 0) {
    if (ans <= n)
      cout << ans << '\n';
    else
      cout << "-1\n";
  } else {
    cout << cnt << '\n';
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

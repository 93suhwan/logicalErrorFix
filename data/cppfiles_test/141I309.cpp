#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n = 2e5 + 1;
int sz = 1;
string ans = "";
bool rec(string& n, string& s, int i = 0, int j = 0) {
  if (i == n.size()) {
    if (j == s.size()) return 1;
    return 0;
  }
  if (j == s.size()) {
    return 0;
  }
  if (s[j] >= n[i]) {
    ans += to_string(s[j] - n[i]);
    if (rec(n, s, i + 1, j + 1)) return 1;
    ans.pop_back();
  }
  if (s.size() > j + 1 && (s[j + 1] - n[i] + 10 <= 9 || (i == 0)) &&
      s[j] == '1') {
    ans += to_string(s[j + 1] - n[i] + 10);
    if (rec(n, s, i + 1, j + 2)) return 1;
    ans.pop_back();
  }
  return 0;
}
string sum(string s1, string s2) {
  if (s1.size() < s2.size()) swap(s1, s2);
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  string ans;
  vector<string> v;
  for (int i = 0; i < s1.size(); i++) {
    if (i >= s2.size()) {
      v.push_back(to_string(s1[i] - '0'));
      continue;
    }
    ll a = s1[i] + s2[i] - '0' - '0';
    v.push_back(to_string(a));
  }
  for (int i = 0; i < v.size(); i++) ans += (v[v.size() - i - 1]);
  return ans;
}
void solve() {
  ans = "";
  string n, s;
  cin >> n >> s;
  ll a = stol(n);
  ll b = stol(s);
  b -= a;
  rec(n, s);
  if (ans.empty()) {
    ans += s[0];
    s.erase(s.begin());
    rec(n, s);
    if (ans.empty())
      cout << -1 << endl;
    else {
      int i = 0;
      while (i < ans.size() && ans[i] == '0') i++;
      for (; i < ans.size(); i++) cout << ans[i];
      cout << endl;
    }
  } else {
    int i = 0;
    while (i < ans.size() && ans[i] == '0') i++;
    for (; i < ans.size(); i++) cout << ans[i];
    cout << endl;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
bool check(string& order, string& t, int l) {
  string s = t.substr(0, l);
  string ans = s;
  for (auto cho : order) {
    string temp = "";
    for (auto ch : s) {
      if (cho != ch) {
        temp += ch;
        ans += ch;
      }
    }
    s = temp;
  }
  if (t == ans) return true;
  return false;
}
void solve() {
  string s;
  cin >> s;
  int last[26];
  int cnt[26] = {0};
  memset(last, -1, sizeof(last));
  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    last[ch - 97] = i;
    cnt[ch - 97]++;
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < 26; i++) {
    if (last[i] != -1) {
      v.push_back({last[i], i});
    }
  }
  sort(v.begin(), v.end());
  string order = "";
  for (auto p : v) {
    order += (char)(p.second + 97);
  }
  int l = 0;
  int i = 1;
  for (auto ch : order) {
    if ((cnt[ch - 97] % i) != 0) {
      cout << -1 << endl;
      return;
    }
    l += (cnt[ch - 97] / i);
    i++;
  }
  if (check(order, s, l)) {
    cout << s.substr(0, l) << " " << order << endl;
    return;
  }
  cout << -1 << endl;
}
int main() {
  int i = 1;
  while (dp.size() < 1000) {
    if (not(i % 3 == 0 or i % 10 == 3)) dp.push_back(i);
    i++;
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

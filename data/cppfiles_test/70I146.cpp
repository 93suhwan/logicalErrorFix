#include <bits/stdc++.h>
using namespace std;
int cnt['z' - 'a' + 1];
pair<string, string> resolve(string s) {
  string order = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    if (!cnt[s[i] - 'a']) {
      order.push_back(s[i]);
    }
    cnt[s[i] - 'a']++;
  }
  int init_length = 0;
  reverse(order.begin(), order.end());
  for (int i = 0; i < order.length(); i++) {
    init_length += cnt[order[i] - 'a'] / (i + 1);
  }
  return {string(s.begin(), s.begin() + init_length), order};
}
bool check(pair<string, string> res, string s) {
  string original = res.first;
  string order = res.second;
  string tmp = original;
  for (auto c : order) {
    string tmp2 = "";
    for (auto i : original) {
      if (i != c) {
        tmp2.push_back(i);
      }
    }
    tmp += tmp2;
    original = tmp2;
  }
  if (tmp == s) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int t;
  cin >> t;
  memset(cnt, 0, sizeof(cnt));
  while (t--) {
    string s;
    cin >> s;
    pair<string, string> res = resolve(s);
    if (check(res, s)) {
      cout << res.first << " " << res.second << endl;
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}

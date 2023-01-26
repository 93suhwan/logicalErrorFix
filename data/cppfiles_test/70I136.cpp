#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }
signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt[27] = {0};
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
      cnt[s[i] - 'a']++;
      mp[s[i]] = i;
    }
    vector<pair<char, int> > v;
    for (char c = 'a'; c <= 'z'; c++) {
      v.push_back(make_pair(c, mp[c]));
    }
    string st = "";
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second == 0) break;
      st = v[i].first + st;
    }
    int num[27] = {0};
    bool f = 0;
    int sum = 0;
    for (int i = 0; i < st.size(); i++) {
      if (cnt[st[i] - 'a'] % (i + 1) != 0)
        f = 1;
      else
        num[st[i] - 'a'] = cnt[st[i] - 'a'] / (i + 1);
      sum += num[st[i] - 'a'];
    }
    if (f) {
      cout << -1 << endl;
      continue;
    }
    string t = s.substr(0, sum), ans = t;
    set<char> se;
    for (int i = 0; i < st.size(); i++) {
      se.insert(st[i]);
      for (int j = 0; j < t.size(); j++)
        if (se.find(t[j]) == se.end()) ans += t[j];
    }
    if (ans == s)
      cout << t << " " << st << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}

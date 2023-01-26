#include <bits/stdc++.h>
using namespace std;
string is_nice(string s, string b) {
  string t = s;
  for (long long i = 0; i < b.length(); i++) {
    string temp = "";
    for (long long j = 0; j < s.length(); j++) {
      if (s[j] != b[i]) temp.push_back(s[j]);
    }
    s = temp;
    t += s;
  }
  return t;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  long long dummy = 0;
  while (T--) {
    string t, ans;
    cin >> t;
    if (dummy > 120) cout << t << "\n";
    dummy++;
    if (dummy > 8) continue;
    map<char, long long> mp, mp1;
    set<char> s;
    for (long long i = 0; i < t.length(); i++) mp[t[i]]++;
    long long size = mp.size(), is_possible = 1;
    for (long long i = t.length() - 1; i >= 0; i--) {
      if (s.find(t[i]) == s.end()) {
        if (mp[t[i]] % size != 0) {
          is_possible = 0;
          break;
        }
        mp[t[i]] /= size;
        size--;
        s.insert(t[i]);
        ans.push_back(t[i]);
      }
    }
    if (is_possible == 0) {
      cout << "-1\n";
      continue;
    }
    for (long long i = 0; i < t.length(); i++) {
      mp1[t[i]]++;
      if (mp1 == mp) {
        reverse(ans.begin(), ans.end());
        if (is_nice(t.substr(0, i + 1), ans) == t) {
          cout << t.substr(0, i + 1) << " " << ans << "\n";
          is_possible = 1;
        } else
          is_possible = 0;
        break;
      }
    }
    if (is_possible == 0) cout << "-1\n";
  }
}

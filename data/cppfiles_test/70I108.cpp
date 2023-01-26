#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long> mp;
    vector<char> v;
    for (long long i = s.size() - 1; i >= 0; i--) {
      if (mp.find(s[i]) == mp.end()) {
        v.push_back(s[i]);
      }
      mp[s[i]]++;
    }
    map<char, long long> check;
    long long len = 0;
    for (long long i = 0; i < v.size(); i++) {
      check[v[i]] = (mp[v[i]]) / (v.size() - i);
      len += check[v[i]];
    }
    string cur = "";
    bool n_ok = false;
    for (long long i = 0; i < len; i++) {
      check[s[i]]--;
      if (check[s[i]] < 0) n_ok = true;
      cur += s[i];
    }
    string predict = cur;
    if (n_ok) {
      cout << -1 << '\n';
      continue;
    }
    s.erase(0, len);
    for (long long x = v.size() - 1; x >= 0; x--) {
      for (long long i = 0; i < cur.size(); i++) {
        if (cur[i] == v[x]) {
          cur.erase(i, 1);
          i--;
        } else if (s[0] == cur[i]) {
          s.erase(0, 1);
        } else {
          n_ok = true;
          break;
        }
      }
      if (n_ok) break;
    }
    if (s.size() != 0 && cur.size() != 0) n_ok = true;
    if (n_ok)
      cout << -1 << '\n';
    else {
      cout << predict << " ";
      for (long long i = v.size() - 1; i >= 0; i--) cout << v[i];
      cout << '\n';
    }
  }
  return 0;
}

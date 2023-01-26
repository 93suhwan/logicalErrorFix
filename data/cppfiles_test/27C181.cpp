#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = LLONG_MAX;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  ;
  while (q--) {
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) {
      cout << "NO" << endl;
      continue;
    }
    vector<long long> v;
    for (int i = 0; i < s.size(); i += 2) {
      if (s[i] == t[0]) {
        v.push_back(i);
        break;
      }
    }
    for (int i = 1; i < s.size(); i += 2) {
      if (s[i] == t[0]) {
        v.push_back(i);
        break;
      }
    }
    if (v.size() == 0) {
      cout << "NO" << endl;
      continue;
    }
    int flag = 0;
    for (auto i : v) {
      int c = 1;
      int y = i + 1;
      while (y < s.size() && c < t.size()) {
        if (s[y] == t[c]) {
          y++;
          c++;
        } else
          y += 2;
      }
      if (c == t.size() && (s.size() - y) % 2 == 0) {
        flag = 1;
        break;
      }
      if (flag == 1) {
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

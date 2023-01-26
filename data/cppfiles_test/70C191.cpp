#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long cnt[26] = {};
    for (char c : s) {
      cnt[c - 'a']++;
    }
    string rem;
    for (long long i = 0; i < s.length(); i++) {
      if (cnt[s[i] - 'a'] == 1) {
        rem += string(1, s[i]);
      }
      cnt[s[i] - 'a']--;
    }
    long long ac[26] = {};
    for (char c : s) {
      ac[c - 'a']++;
    }
    bool flag = 1;
    for (long long i = 0; i < rem.size(); i++) {
      if (ac[rem[i] - 'a'] % (i + 1) != 0)
        flag = 0;
      else {
        ac[rem[i] - 'a'] /= (i + 1);
      }
    }
    string r;
    for (char c : s) {
      if (ac[c - 'a']) {
        r += string(1, c);
      } else {
        break;
      }
      ac[c - 'a']--;
    }
    string temp = r;
    long long c[26] = {};
    for (char ci : s) {
      c[ci - 'a']++;
    }
    for (long long j = 0; j < rem.size(); j++) {
      c[rem[j] - 'a'] = 0;
      for (long long i = 0; i < r.size(); i++) {
        if (c[r[i] - 'a']) {
          temp += string(1, r[i]);
        }
      }
    }
    if (temp != s) {
      flag = 0;
    }
    if (flag) {
      cout << r << " " << rem;
    } else {
      cout << -1;
    }
    cout << endl;
  }
}

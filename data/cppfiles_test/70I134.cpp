#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s == "") {
      break;
    }
    vector<pair<long long, char>> v(26);
    for (long long i = 0; i < 26; i++) {
      v[i].second = 'a' + i;
    }
    set<char> set1;
    for (long long i = 0; i < s.length(); i++) {
      set1.insert(s[i]);
      v[s[i] - 'a'].first++;
    }
    long long x = set1.size() + 1;
    string s1;
    set1.clear();
    for (long long i = s.length() - 1; i >= 0; i--) {
      if (set1.find(s[i]) == set1.end()) {
        set1.insert(s[i]);
        s1 += s[i];
      }
    }
    reverse(s1.begin(), s1.end());
    long long length = 0;
    long long flag = 0;
    for (long long i = 0; i < 26; i++) {
      if (v[i].first != 0) {
        long long p = 0;
        for (long long j = 0; j < s1.length(); j++) {
          if (v[i].second == s1[j]) {
            p = j + 1;
            break;
          }
        }
        length += v[i].first / p;
        if (v[i].first % p != 0) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      cout << "-1" << endl;
      continue;
    }
    string ans;
    for (long long i = 0; i < length; i++) {
      ans += s[i];
    }
    string ans1 = ans;
    long long count1 = 0;
    for (long long i = 0; i < s.length();) {
      long long count = 0;
      while (count < ans.length()) {
        if (s[i] != ans[count]) {
          flag = 1;
          break;
        }
        if (ans[count] == s1[count1]) {
          ans.erase(count, 1);
          count--;
        }
        i++;
        count++;
      }
      count1++;
      if (flag) {
        break;
      }
    }
    if (flag) {
      cout << "-1" << endl;
      break;
    }
    if (ans1 == "" || s1 == "") {
      cout << "-1" << endl;
      continue;
    }
    cout << ans1 << " " << s1 << endl;
  }
}

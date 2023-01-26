#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    string s, T;
    string ans = "", final = "";
    cin >> s >> T;
    if (T == "abc") {
      map<char, int> m;
      vector<int> v(3);
      int temp = 0;
      for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
      }
      for (auto it = m.begin(); it != m.end(); it++) {
        ans += it->first;
        v.push_back(it->second);
        temp++;
        if (temp == 3) {
          break;
        }
      }
      if (ans == "abc") {
        sort(s.begin(), s.end());
        string s1 = "", s2 = "", s3 = "", s4 = "";
        for (int i = 0; i < s.length(); i++) {
          if (s[i] == 'a') {
            s1 += 'a';
          } else if (s[i] == 'b') {
            s3 += 'b';
          } else if (s[i] == 'c') {
            s2 += 'c';
          } else {
            s4 += s[i];
          }
        }
        final = s1 + s2 + s3 + s4;
      } else {
        sort(s.begin(), s.end());
        final += s;
      }
    } else {
      sort(s.begin(), s.end());
      final += s;
    }
    cout << final << endl;
    t--;
  }
  return 0;
}

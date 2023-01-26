#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    string ss = s + s;
    sort(ss.begin(), ss.end());
    sort(t.begin(), t.end());
    int sz = s.size();
    int tz = t.size();
    if (s[sz] == t[1] && tz > sz) {
      cout << "NO" << endl;
    } else if (ss.find(t) != string::npos) {
      cout << "YES" << endl;
    }
  }
}

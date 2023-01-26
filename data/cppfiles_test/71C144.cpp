#include <bits/stdc++.h>
using namespace std;
int t;
int k;
string s;
string solve() {
  while (1) {
    set<char> q;
    for (int i = 0; i < s.size(); i++) q.insert(s[i]);
    if (q.size() <= k) return s;
    q.clear();
    for (int pre = 0; pre < s.size(); pre++) {
      q.insert(s[pre]);
      if (q.size() > k) {
        while (s[pre] == '9') pre--;
        s[pre]++;
        for (int i = pre + 1; i < s.size(); i++) {
          s[i] = '0';
        }
        break;
      }
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> s >> k;
    cout << solve() << endl;
  }
  return 0;
}

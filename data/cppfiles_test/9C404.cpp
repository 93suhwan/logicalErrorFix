#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> tmp;
    for (int i = 0; i < s.size(); i++) {
      tmp[s[i]]++;
    }
    int ans = 0, cnt = 0;
    for (pair<char, int> x : tmp) {
      if (x.second >= 2) {
        ans++;
      } else if (x.second) {
        cnt++;
      }
    }
    cout << ans + cnt / 2 << endl;
  }
}

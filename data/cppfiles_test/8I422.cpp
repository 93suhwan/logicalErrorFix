#include <bits/stdc++.h>
using namespace std;
const double Pi = 3.1415926535897932384626433832795;
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    set<char> ss;
    for (int i = 0; i < s.size(); i++) {
      ss.insert(s[i]);
    }
    int n = ss.size();
    if (n == 1) {
      if (s.size() > 1) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      if (s.size() % 2 == 0) {
        cout << s.size() / 2 << endl;
      } else {
        cout << (s.size() - 1) / 2 << endl;
      }
    }
  }
}

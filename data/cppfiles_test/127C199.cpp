#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    cin >> s >> t;
    sort(s.begin(), s.end());
    if (t[0] != 'a' || t[1] == 'c' || s[0] != 'a') {
      cout << s << '\n';
      continue;
    }
    int dem = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'b') {
        dem++;
        continue;
      }
      if (s[i] > 'c') {
        while (dem-- && dem >= 0) cout << 'b';
      }
      cout << s[i];
    }
    while (dem-- && dem >= 0) cout << 'b';
    cout << '\n';
  }
}

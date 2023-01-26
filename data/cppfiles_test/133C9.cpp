#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string t;
    vector<string> s;
    for (int i = 0; i < n - 2; i++) {
      string x;
      cin >> x;
      s.push_back(x);
    }
    t = s[0];
    int d = 0;
    for (int i = 1; i < n - 2; i++) {
      if (s[i][0] == s[i - 1][1]) {
        t += s[i][1];
      } else {
        t += s[i][0];
        t += s[i][1];
        d++;
      }
    }
    if (d == 0) {
      t += "a";
    }
    cout << t << endl;
  }
  return 0;
}

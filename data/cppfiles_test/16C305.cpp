#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, s1;
    cin >> s;
    s1 = s;
    int f = 0;
    sort(s.begin(), s.end());
    for (i = 0; i < s.size(); i++) {
      if (s[i] != s1[i]) {
        f++;
      }
    }
    cout << f << endl;
  }
}

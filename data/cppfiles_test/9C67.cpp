#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int i = 0, natija = 0;
    while (i != s.size()) {
      int m = upper_bound(s.begin(), s.end(), s[i]) - s.begin();
      int l = m - i;
      if (l == 1) {
        natija++;
      } else {
        natija += 2;
      }
      i = m;
    }
    cout << natija / 2 << "\n";
  }
  return 0;
}

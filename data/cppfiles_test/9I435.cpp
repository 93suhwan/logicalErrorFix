#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    int repet = 0;
    cin >> s;
    int colour = 0;
    int colour1 = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == s[i + 1] && repet == 0) {
        colour++;
        i++;
        repet = 1;
      } else if (s[i] != s[i + 1]) {
        colour1++;
        repet = 0;
      }
    }
    cout << colour + (colour1 / 2) << endl;
  }
}

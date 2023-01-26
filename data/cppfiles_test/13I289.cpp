#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, counta = 0, countb = 0, countc = 0;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') {
        counta++;
      } else if (s[i] == 'B') {
        countb++;
      } else
        countc++;
    }
    if ((counta + countc) == countb) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}

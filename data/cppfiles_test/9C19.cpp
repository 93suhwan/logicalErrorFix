#include <bits/stdc++.h>
using namespace std;
bool ACS(string s) {
  int n1 = s.length();
  for (int i = 1; i < n1; i++)
    if (s[i] != s[0]) return false;
  return true;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() == 1)
      cout << 0 << endl;
    else if (s[0] == s[1] && ACS(s))
      cout << 1 << endl;
    else {
      int ss1 = 0;
      map<char, int> m1;
      for (int i = 0; i < s.length(); i++) m1[s[i]]++;
      for (int i = 0; i < m1.size(); i++) {
        if (m1[i] > 2)
          ss1 = ss1 + 2;
        else
          ss1 = ss1 + m1[i];
      }
      if (ss1 % 2)
        cout << (ss1 - 1) / 2 << endl;
      else
        cout << ss1 / 2 << endl;
    }
  }
  return 0;
}

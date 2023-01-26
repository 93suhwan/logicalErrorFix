#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k = s.length();
    if (k % 2 == 0) {
      k /= 2;
      string s1 = s.substr(0, (k / 2) + 1);
      string s2 = s.substr((k / 2) + 1, k);
      if (s1 == s2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "NO" << endl;
  }
}

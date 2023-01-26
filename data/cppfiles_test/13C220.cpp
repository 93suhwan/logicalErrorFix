#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int A = 0, B = 0, C = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == 'A')
        A++;
      else if (s[i] == 'B')
        B++;
      else
        C++;
    }
    if (B >= A && B - A == C)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

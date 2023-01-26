#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0, b = 0, c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else if (s[i] == 'C')
        c++;
    }
    if (a + c == b && a ^ b ^ c == 0)
      cout << "Yes" << endl;
    else
      cout << "No";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int N;
string s;
int main() {
  cin >> N;
  while (N--) {
    cin >> s;
    int ab = 0, ba = 0;
    int len = s.length();
    if (s.length() == 1) {
      cout << s << endl;
      continue;
    }
    for (int i = 0; s[i + 1] != '\0'; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') ab++;
      if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    }
    if (ab != ba) {
      if (s[0] == 'b')
        s[0] = 'a';
      else if (s[0] == 'a')
        s[0] = 'b';
    }
    cout << s << endl;
  }
}

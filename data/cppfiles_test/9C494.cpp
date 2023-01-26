#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    int ch[26];
    memset(ch, 0, sizeof(ch));
    for (int i = 0; i < s.length(); i++) {
      ch[s[i] - 'a']++;
    }
    int left = 0;
    for (int i = 0; i < 26; i++) {
      if (ch[i] > 1) {
        left += (ch[i] - 2);
      }
    }
    int n = s.length() - left;
    cout << n / 2 << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ab = 0, ba = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        ab++;
      }
      if (s[i] == 'b' && s[i + 1] == 'a') {
        ba++;
      }
    }
    if (ab == ba) {
      cout << s << endl;
      continue;
    } else {
      long long int c = min(ab, ba);
      long long int d = s.size();
      long long int e = d - (c * 4);
      for (long long int i = 0; i < c; i++) cout << "abba";
      for (long long int i = 0; i < e; i++) cout << 'a';
    }
    cout << endl;
  }
  return 0;
}

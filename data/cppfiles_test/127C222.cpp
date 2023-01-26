#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string second, t;
    cin >> second >> t;
    sort(second.begin(), second.end());
    unordered_map<char, int> m;
    for (int(i) = (0); (i) < ((int)second.size()); (i)++) {
      m[second[i]]++;
    }
    if (m['a'] == 0 || m['b'] == 0 || m['c'] == 0 || t[0] != 'a') {
      cout << second << endl;
    } else {
      if (t[1] == 'b') {
        while (m['a']) {
          cout << 'a';
          m['a']--;
        }
        for (char c = 'c'; c <= 'z'; c++) {
          if (m[c] != 0) {
            while (m[c]) {
              cout << c;
              m[c]--;
            }
            break;
          }
        }
        for (char c = 'b'; c <= 'z'; c++) {
          while (m[c]) {
            cout << c;
            m[c]--;
          }
        }
        cout << endl;
      } else {
        cout << second << endl;
      }
    }
  }
  return 0;
}

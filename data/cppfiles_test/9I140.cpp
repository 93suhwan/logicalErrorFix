#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, count = 0;
    string s;
    char a;
    cin >> s;
    sort(s.begin(), s.end());
    int length = s.size();
    k = length / 2;
    for (int i = 1; i < s.size(); i++) {
      a = s[i - 1];
      if (s[i] == s[i - 1]) {
        count++;
        if (count >= 2 && a != s[i]) {
          if (length % 2 == 1) {
            length--;
          } else
            k--;
          count = 0;
        }
        if (count >= 2 && a == s[i]) {
          if (length % 2 == 1) {
            length--;
          } else
            k--;
        }
      } else
        count--;
    }
    if (k <= 0) k = 1;
    if (length == 1) k = 0;
    cout << k << "\n";
  }
}

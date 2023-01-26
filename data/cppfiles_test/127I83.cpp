#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    string ans = "";
    int a = 0, b = 0, c = 0;
    int j = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'a') a++;
      if (s[j] == 'b') b++;
      if (s[j] == 'c') c++;
      if (s[j] > 'c') break;
    }
    for (int i = 0; i < 3; i++) {
      if (t[i] == 'a') {
        t.erase(t.begin() + i);
        break;
      }
    }
    if (t[0] == 'c') {
      while (a) {
        ans += 'a';
        a--;
      }
      while (b) {
        ans += 'b';
        b--;
      }
      while (c) {
        ans += 'c';
        c--;
      }
    } else {
      if (a > 0) {
        while (a) {
          ans += 'a';
          a--;
        }
        while (c) {
          ans += 'c';
          c--;
        }
        while (b) {
          ans += 'b';
          b--;
        }
      } else {
        while (b) {
          ans += 'b';
          b--;
        }
        while (c) {
          ans += 'c';
          c--;
        }
      }
    }
    for (; j < s.size(); j++) {
      ans += s[j];
    }
    cout << ans << "\n";
  }
}

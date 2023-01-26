#include <bits/stdc++.h>
using namespace std;
long long int mymax(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else
    return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int ab = 0, ba = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        ab++;
      } else if (s[i] == 'b' && s[i + 1] == 'a') {
        ba++;
      }
    }
    if (ab == ba) {
      cout << s << endl;
    } else {
      if (ab > ba) {
        int c1 = 0;
        int c2 = 0;
        string s1 = s, s2 = s;
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'b') {
            c1++;
            s1[i] = 'a';
          } else {
            break;
          }
        }
        for (int i = 0; i < n; i++) {
          if (s[i] == 'a') {
            c2++;
            s2[i] = 'b';
          } else {
            break;
          }
        }
        if (c1 < c2) {
          cout << s1 << endl;
        } else {
          cout << s2 << endl;
        }
      } else {
        int c1 = 0;
        int c2 = 0;
        string s1 = s, s2 = s;
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'a') {
            c1++;
            s1[i] = 'b';
          } else {
            break;
          }
        }
        for (int i = 0; i < n; i++) {
          if (s[i] == 'b') {
            c2++;
            s2[i] = 'a';
          } else {
            break;
          }
        }
        if (c1 < c2) {
          cout << s1 << endl;
        } else {
          cout << s2 << endl;
        }
      }
    }
  }
}

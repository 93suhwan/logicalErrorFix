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
        int ind = -1;
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'b') {
            c1++;
          } else {
            break;
          }
        }
        if (c1 >= 1) {
          s1[n - 1] = 'a';
          c1 = 1;
        }
        cout << s1 << endl;
      } else {
        int c1 = 0;
        int c2 = 0;
        int ind = -1;
        string s1 = s, s2 = s;
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'a') {
            c1++;
            ind = i;
          } else {
            break;
          }
        }
        if (c1 >= 1) {
          s1[n - 1] = 'b';
          c1 = 1;
        }
        cout << s1 << endl;
      }
    }
  }
}

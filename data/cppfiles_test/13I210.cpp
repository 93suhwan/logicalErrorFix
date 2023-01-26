#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int i, j, sz;
    string s;
    cin >> s;
    sz = s.size();
    if (sz % 2) {
      cout << "NO"
           << "\n";
    } else {
      long long int a = 0, b = 0, c = 0;
      for (i = 0; i < sz; i++) {
        if (s[i] == 'A')
          a++;
        else if (s[i] == 'B')
          b++;
        else
          c++;
      }
      if (b == 0) {
        cout << "NO"
             << "\n";
        continue;
      }
      long long int mn = min(a, min(b, c));
      if (mn == sz / 3) {
        cout << "YES"
             << "\n";
        continue;
      }
      if (mn == a) {
        b = b - a;
        if (b == c) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else if (mn == b) {
        c = c - b;
        if (a == c) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else {
        b = b - c;
        if (a == b) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      }
    }
  }
  return 0;
}

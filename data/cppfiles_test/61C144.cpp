#include <bits/stdc++.h>
using namespace std;
int main() {
  long long z;
  cin >> z;
  while (z--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long m = s.size();
    long long k;
    long long q = 0;
    for (long long i = 0; i <= m - 1; i++) {
      if (s[i] == 'B' || s[i] == 'R') {
        k = i;
        q = 1;
        break;
      }
    }
    long long f1 = 0, f2 = 0;
    if (q == 1) {
      for (long long i = k; i <= m - 1; i++) {
        if (s[i] == 'B') {
          f1 = 1;
          f2 = 0;
        } else if (s[i] == 'R') {
          f2 = 1;
          f1 = 0;
        } else {
          if (f1 == 1) {
            s[i] = 'R';
            f2 = 1;
            f1 = 0;
          } else if (f2 == 1) {
            s[i] = 'B';
            f1 = 1;
            f2 = 0;
          }
        }
      }
      for (long long i = k; i >= 0; i--) {
        if (s[i] == 'B') {
          f1 = 1;
          f2 = 0;
        } else if (s[i] == 'R') {
          f2 = 1;
          f1 = 0;
        } else {
          if (f1 == 1) {
            s[i] = 'R';
            f2 = 1;
            f1 = 0;
          } else if (f2 == 1) {
            s[i] = 'B';
            f1 = 1;
            f2 = 0;
          }
        }
      }
      for (long long i = 0; i <= m - 1; i++) {
        cout << s[i];
      }
      cout << endl;
    } else {
      for (long long i = 0; i <= m - 1; i++) {
        if (i % 2 != 0) {
          cout << "B";
        } else {
          cout << "R";
        }
      }
      cout << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int ceilab(int a, int b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
int grecomdiv(int a, int b) {
  if (b == 0) return a;
  return grecomdiv(b, a % b);
}
int sumofnum(string s) {
  int t = 0;
  for (int i = 0; i < s.length(); i++) {
    t += (s[i] - 48);
  }
  return t;
}
int dp[5001][5001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    int a;
    cin >> a;
    string s;
    cin >> s;
    int m = 0;
    for (int i = 0; i < a; i++) {
      if ((s[i] - '0') > 3) {
        if ((s[i] - '0') % 2 == 0 || (s[i] - '0') % 3 == 0) {
          cout << 1 << endl << (s[i] - '0') << endl;
          m++;
          break;
        }
      } else if ((s[i] - '0') == 1) {
        cout << 1 << endl << 1 << endl;
        m++;
        break;
      }
    }
    if (m == 0) {
      for (int i = 0; i < a; i++) {
        for (int k = i + 1; k < a; k++) {
          int p = (s[i] - '0') * 10 + (s[k] - '0');
          for (int j = 2; j < 10; j++) {
            if (p % j == 0) {
              cout << 2 << endl << p << endl;
              m++;
              break;
            }
          }
          if (m != 0) {
            break;
          }
        }
        if (m != 0) {
          break;
        }
      }
    }
    if (m == 0) {
      for (int i = 0; i < a; i++) {
        for (int k = i + 1; k < a; k++) {
          for (int l = k + 1; l < a; l++) {
            int p = (s[i] - '0') * 100 + (s[k] - '0') * 10 + (s[l] - '0');
            for (int j = 2; j < 10; j++) {
              if (p % j == 0) {
                cout << 3 << endl << p << endl;
                m++;
                break;
              }
            }
            if (m != 0) {
              break;
            }
          }
          if (m != 0) {
            break;
          }
        }
        if (m != 0) {
          break;
        }
      }
    }
  }
  return 0;
}

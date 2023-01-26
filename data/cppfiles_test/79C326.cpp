#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.length() == 1) {
      cout << 1 << endl << s << endl;
    } else {
      bool flag = false;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
            s[i] == '9') {
          cout << 1 << endl << s[i] << endl;
          flag = true;
          break;
        }
      }
      if (flag == false) {
        for (int i = 0; i < n; i++) {
          if (s[i] == '0') {
            cout << 2 << endl << s[i - 1] << s[i] << endl;
            break;
            flag = true;
          }
        }
      }
      long long int freq[10] = {0};
      if (flag == false) {
        for (int i = 0; i < n; i++) {
          freq[s[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
          if (freq[i] > 1) {
            cout << 2 << endl << i << i << endl;
            flag = true;
            break;
          }
        }
        if (!flag) {
          if (freq[2] > 0 and freq[5] > 0) {
            int v1 = 0, v2 = 0;
            for (int i = 0; i < n; i++) {
              if (s[i] == '2') {
                v1 = i;
              }
              if (s[i] == '5') {
                v2 = i;
              }
            }
            if (v1 > v2) {
              cout << 2 << endl << 52 << endl;
            } else {
              cout << 2 << endl << 25 << endl;
            }
          } else if (freq[2] > 0 and freq[7] > 0) {
            int v1 = 0, v2 = 0;
            for (int i = 0; i < n; i++) {
              if (s[i] == '2') {
                v1 = i;
              }
              if (s[i] == '7') {
                v2 = i;
              }
            }
            if (v1 > v2) {
              cout << 2 << endl << 72 << endl;
            } else {
              cout << 2 << endl << 27 << endl;
            }
          } else if (freq[5] > 0 and freq[7] > 0) {
            int v1 = 0, v2 = 0;
            for (int i = 0; i < n; i++) {
              if (s[i] == '5') {
                v1 = i;
              }
              if (s[i] == '7') {
                v2 = i;
              }
            }
            if (v1 > v2) {
              cout << 2 << endl << 75 << endl;
            } else {
              cout << 2 << endl << 57 << endl;
            }
          } else {
            if (freq[2] > 0 and freq[3] > 0) {
              int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
              for (int i = 0; i < n; i++) {
                if (s[i] == '2') {
                  v1 = i;
                }
                if (s[i] == '3') {
                  v2 = i;
                }
                if (s[i] == '7') {
                  v4 = i;
                }
                if (s[i] == '5') {
                  v3 = i;
                }
              }
              if (v1 > v2) {
                cout << 2 << endl << 32 << endl;
              }
            } else if (freq[3] > 0 and freq[5] > 0) {
              cout << 2 << endl << 35 << endl;
            }
          }
        }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline long long int sbt(long long int x) { return __builtin_popcount(x); }
inline long long int mul(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a * b) % m;
}
inline long long int add(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a + b) % m;
}
inline long long int sub(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a - b + m) % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int no[10];
    memset(no, 0, sizeof(no));
    for (int i = 0; i < k; i++) {
      if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
        cout << "1"
             << "\n";
        cout << s[i] << "\n";
        break;
      } else {
        if (s[i] == '2') {
          if (no[3]) {
            cout << "2"
                 << "\n";
            cout << "32"
                 << "\n";
            break;
          }
          if (no[5]) {
            cout << "2"
                 << "\n";
            cout << "52"
                 << "\n";
            break;
          }
          if (no[2]) {
            cout << "2"
                 << "\n";
            cout << "22"
                 << "\n";
            break;
          }
          if (no[7]) {
            cout << "2"
                 << "\n";
            cout << "72"
                 << "\n";
            break;
          }
          no[2] = 1;
        } else if (s[i] == '3') {
          if (no[3]) {
            cout << "2"
                 << "\n";
            cout << "33"
                 << "\n";
            break;
          }
          no[3] = 1;
        } else if (s[i] == '5') {
          if (no[3]) {
            cout << "2"
                 << "\n";
            cout << "35"
                 << "\n";
            break;
          }
          if (no[5]) {
            cout << "2"
                 << "\n";
            cout << "55"
                 << "\n";
            break;
          }
          if (no[2]) {
            cout << "2"
                 << "\n";
            cout << "25"
                 << "\n";
            break;
          }
          if (no[7]) {
            cout << "2"
                 << "\n";
            cout << "75"
                 << "\n";
            break;
          }
          no[5] = 1;
        } else if (s[i] == '7') {
          if (no[5]) {
            cout << "2"
                 << "\n";
            cout << "57"
                 << "\n";
            break;
          }
          if (no[2]) {
            cout << "2"
                 << "\n";
            cout << "27"
                 << "\n";
            break;
          }
          if (no[7]) {
            cout << "2"
                 << "\n";
            cout << "77"
                 << "\n";
            break;
          }
          no[7] = 1;
        }
      }
    }
  }
}

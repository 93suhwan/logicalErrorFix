#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long ceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
void solve() {
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    sort(s.begin(), s.end());
    if (t == "abc") {
      int x, y, z;
      int f1 = 0, f2 = 0, f3 = 0;
      if (s[0] == 'a') {
        for (int i = 0; i < n; i++) {
          if (s[i] == 'b') {
            f1 = 1;
            x = i;
            break;
          }
        }
        for (int i = 0; i < n; i++) {
          if (s[i] == 'c') {
            f2 = 1;
            y = i;
            break;
          }
        }
        for (int i = 0; i < n; i++) {
          if (s[i] > 'c') {
            f3 = 1;
            z = i;
            break;
          }
        }
        if (f1 == 1 && f2 == 1) {
          for (int i = 0; i < x; i++) cout << s[i];
          if (f3 == 0)
            for (int i = y; i < n; i++) cout << s[i];
          else if (f3 == 1) {
            for (int i = y; i < z; i++) cout << s[i];
          }
          for (int i = x; i < y; i++) cout << s[i];
          if (f3 == 1) {
            for (int i = z; i < n; i++) cout << s[i];
          }
          cout << endl;
        } else
          cout << s << endl;
      } else
        cout << s << endl;
    } else
      cout << s << endl;
  }
}
int main() { solve(); }

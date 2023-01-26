#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long x = (n) / 2;
    bool f = 1;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') cnt++;
    }
    if (cnt == n) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
      f = 0;
    }
    if (f)
      for (int i = 0; i < x; i++) {
        if (s[i] == '0') {
          f = 0;
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
          break;
        }
      }
    if (f)
      for (int i = x; i < n; i++) {
        if (s[i] == '0') {
          f = 0;
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
          break;
        }
      }
  }
}

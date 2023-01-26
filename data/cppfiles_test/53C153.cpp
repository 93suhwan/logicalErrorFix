#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long tttt{};
  cin >> tttt;
  while (tttt--) {
    long long n{};
    char c{};
    cin >> n >> c;
    string s;
    cin >> s;
    bool flag_zero = true;
    for (auto i : s) {
      if (i != c) {
        flag_zero = false;
        break;
      }
    }
    if (flag_zero) {
      cout << "0\n";
    } else {
      bool flag_one = false;
      for (long long i = n / 2; i < n; i++) {
        if (s[i] == c) {
          cout << "1\n" << i + 1 << "\n";
          flag_one = true;
          break;
        }
      }
      if (!flag_one) {
        if (n % 2) {
          cout << "2\n2 " << n << "\n";
        } else {
          cout << "2\n2 " << n - 1 << "\n";
        }
      }
    }
  }
  return 0;
}

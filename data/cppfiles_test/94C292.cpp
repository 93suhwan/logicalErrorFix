#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, it;
  cin >> t;
  for (it = 1; it <= t; it++) {
    int v, r;
    long long i, j, k, len, x, y, c, d, a, b;
    string str, str1, str2;
    cin >> str;
    len = str.length();
    for (i = 0; i < len; i++) {
      if (i % 2 == 0) {
        str1.push_back(str[i]);
      } else {
        str2.push_back(str[i]);
      }
    }
    if (len == 1) {
      x = stoi(str1);
      cout << (x - 1) << endl;
    } else {
      x = stoi(str1);
      y = stoi(str2);
      cout << ((x + 1) * (y + 1)) - 2 << endl;
    }
  }
  return 0;
}

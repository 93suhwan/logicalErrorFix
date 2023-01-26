#include <bits/stdc++.h>
using namespace std;
int max(int a, int b, int c) {
  if (a >= b && a >= c) return a;
  if (b >= a && b >= c) return b;
  if (c >= a && c >= b) return c;
}
int test(string str) {
  int len = str.length();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'A')
      a += 1;
    else if (str[i] == 'B')
      b += 1;
    else if (str[i] == 'C')
      c += 1;
  }
  int maximum = max(a, b, c);
  if ((maximum == a && maximum == b + c) ||
      (maximum == c && maximum == a + b) ||
      (maximum == b && maximum == a + c)) {
    if (maximum == a && (a != b && a != c)) {
      return 0;
    } else {
      return 1;
    }
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    if (test(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

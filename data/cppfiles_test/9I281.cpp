#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y = 0, number1 = 0, number2 = 0, m = 1;
  string s;
  cin >> n;
  while (n != 0) {
    cin >> s;
    x = s.size();
    int a[x];
    for (int i = 0; i < x; i++) a[i] = 0;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        if (s[i] == s[j]) a[i] = a[i] + 1;
      }
    }
    for (int i = 0; i < x; i++) {
      if (a[i] == 3) number1 = a[i] + number1;
      if (a[i] == 2) number2 = number2 + a[i];
      if (s[i] == s[i + 1]) m = m + 1;
    }
    if (m == x)
      cout << 1;
    else
      cout << number1 / 9 + number2 / 4 + (x - (number1 / 3 + number2 / 2)) / 2;
    number1 = 0;
    number2 = 0;
    m = 1;
    n--;
    cout << endl;
  }
  return 0;
}

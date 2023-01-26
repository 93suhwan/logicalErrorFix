#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y = 0, number1 = 0, number2 = 0, m = 0;
  string s, s1;
  cin >> n;
  while (n != 0) {
    cin >> s;
    x = s.size();
    s1 = s;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        if (s[i] == s1[j]) {
          number1 = number1 + 1;
          s1[j] = j;
        }
      }
      if (number1 >= 3) {
        m = m + number1;
        number2 = number2 + 1;
      }
      number1 = 0;
    }
    cout << number2 + (x - m) / 2;
    number2 = 0;
    m = 0;
    n--;
    cout << endl;
  }
  return 0;
}

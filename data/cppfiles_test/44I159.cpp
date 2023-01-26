#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int times = 0;
  cin >> times;
  for (int i = 0; i < times; ++i) {
    long long int c = 0, d = 0;
    long long int output = 0;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      output = 0;
      cout << output << "\n";
      continue;
    } else if (c == d) {
      output = 1;
      cout << output << "\n";
      continue;
    } else if (c == 0 || d == 0) {
      output = 2;
      cout << output << "\n";
      continue;
    } else if ((c == d + 1 || c == d - 1) || (d == c + 1 || d == c - 1)) {
      output = -1;
      cout << output << "\n";
      continue;
    } else if ((c == 0 || d == 0)) {
      if (c == 0 && d % 2 != 0) {
        output = -1;
        cout << output << "\n";
      } else if (d == 0 && c % 2 != 0) {
        output = -1;
        cout << output << "\n";
      }
      continue;
    } else {
      if ((c % 2 == 0 && d % 2 == 0) || (c % 2 != 0 && d % 2 != 0)) {
        output = 2;
        cout << output << "\n";
        continue;
      } else {
        output = -1;
        cout << output << "\n";
        continue;
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int n;
    cin >> n;
    if (n == 1)
      cout << 'a' << endl;
    else if (n % 2 == 0) {
      for (int j = 0; j < n / 2; ++j) putchar('a');
      cout << 'b';
      for (int j = 1; j < n / 2; ++j) putchar('a');
      cout << endl;
    } else {
      for (int j = 0; j < n / 2; ++j) putchar('a');
      cout << "bc";
      for (int j = 1; j < n / 2; ++j) putchar('a');
      cout << endl;
    }
  }
  return 0;
}

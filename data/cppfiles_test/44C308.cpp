#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int times = 0;
  cin >> times;
  for (int i = 0; i < times; ++i) {
    long long int c = 0, d = 0;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << "\n";
    } else if (c == d) {
      cout << 1 << "\n";
    } else if (c % 2 == d % 2) {
      cout << 2 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}

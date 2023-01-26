#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int times = 0;
  cin >> times;
  for (int i = 0; i < times; ++i) {
    long long a = 0, b = 0;
    cin >> b >> a;
    if (b <= a / 2 + 1)
      cout << a - a / 2 - 1 << endl;
    else
      cout << a - b << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    if (x < 9)
      cout << 0 << endl;
    else
      cout << (x / 10) + (x % 10 == 9) << endl;
  }
  return 0;
}

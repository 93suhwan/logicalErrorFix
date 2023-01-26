#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    a = a % 4;
    b = b % 4;
    c = c % 2;
    long long minn = 0x3f3f3f3f;
    for (int i = 0; i <= a; ++i) {
      for (int j = 0; j <= b; ++j) {
        for (int k = 0; k <= c; ++k) {
          minn = min(minn, abs(i * 1 + j * 2 + k * 3 -
                               ((a - i) + (b - j) * 2 + (c - k) * 3)));
        }
      }
    }
    cout << minn << endl;
  }
  return 0;
}

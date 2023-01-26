#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long s1 = 0;
    a %= 2;
    b %= 2;
    c %= 2;
    if ((a + b * 2 + c * 3) % 2 == 0) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}

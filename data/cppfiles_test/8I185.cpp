#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << 1 << " " << 0 << endl;
      continue;
    }
    if (n == 2) {
      cout << 0 << " " << 1 << endl;
      continue;
    }
    int x = 0, y = 0;
    if (n % 3 == 0) {
      y = n / 3;
      x = y;
    } else {
      y = n / 3;
      x = y;
      y++;
    }
    cout << x << " " << y << endl;
  }
  return 0;
}

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
    int i = 0, j = 0;
    y = n / 3;
    x = (n - (y * 2));
    j = (n + 1) / 3;
    i = (n - (j * 2));
    if (abs(x - y) < abs(i - j))
      cout << x << " " << y << endl;
    else
      cout << i << " " << j << endl;
  }
  return 0;
}

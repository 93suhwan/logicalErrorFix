#include <bits/stdc++.h>
using namespace std;
int main() {
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    if (n % 2 == 0)
      printf("2 %d 1\n", n - 3);
    else {
      n = (n - 1) / 2;
      if (n & 1)
        printf("%d %d 1\n", n + 2, n - 2);
      else
        printf("%d %d 1\n", n - 1, n + 1);
    }
  }
  return 0;
}
